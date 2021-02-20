#include "mainwindow.h"
#include"ui_mainwindow.h"
#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    td = new ThresholdDialog(&matt);
    sd = new ScaleimageDialog(&matt);
    ecd = new ErosionCircleDialog(&matt);
    dd = new DilationDialog(&matt);
    cd = new ClosiongDialog(&matt);
    od = new OpeningDialog(&matt);
    selectd = new SelectDialog(&matt);
    cssmd = new CreateScaledShapeModelDialog(&matt);
    init();
    matt.domCount = 0;
    okNg(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    //设置halcon的文件路径为utf8，解决中文乱码
    SetSystem("filename_encoding", "utf8");
    //生成空图像
    GenEmptyObj(&matt.m_image);

    //获取图像显示控件的句柄
    matt.m_WindowHandle = NULL;
    matt.m_hLabelID = (Hlong)ui->image->winId();
}

void MainWindow::showImg()
{
    //判断图像是否为空
        HalconCpp::HTuple isEqual;
        HalconCpp::HObject emptyObj;
        GenEmptyObj(&emptyObj);
        TestEqualObj(emptyObj,matt.m_image, &isEqual);
        if ((Hlong)isEqual){
            return;
        }
        if (matt.m_WindowHandle != NULL){
            //如果有图像，则先清空图像
            DetachBackgroundFromWindow(matt.m_WindowHandle);
        }else{
            //打开窗口
            OpenWindow(0, 0, ui->image->width(), ui->image->height(), matt.m_hLabelID, "visible", "", &matt.m_WindowHandle);
        }
        ui->image->setHalconWnd(matt.m_image,matt.m_WindowHandle,ui->image);
        GetImageSize(matt.m_image, &matt.m_imgWidth, &matt.m_imgHeight);
        //判断是否等比缩放
        if (matt.m_bIsEqualScale){
            //获取缩放系数
            TupleMin2(1.0 * ui->image->width() / matt.m_imgWidth, 1.0 * ui->image->height() / matt.m_imgHeight, &matt.m_hvScaledRate);
            //进行图像缩放
            ZoomImageFactor(matt.m_image, &matt.m_hResizedImg, matt.m_hvScaledRate, matt.m_hvScaledRate, "constant");
            GetImageSize(matt.m_hResizedImg, &matt.m_scaledWidth, &matt.m_scaledHeight);
        }
        SetWindowExtents(matt.m_WindowHandle, 0, 0, ui->image->width(), ui->image->height());
        SetPart(matt.m_WindowHandle, 0, 0, matt.m_imgHeight - 1, matt.m_imgWidth - 1);
        AttachBackgroundToWindow(matt.m_image, matt.m_WindowHandle);
        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetColor(matt.m_WindowHandle, "green");
        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetDraw(matt.m_WindowHandle, "margin");
        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetLineWidth(matt.m_WindowHandle, 2);
        SetColored(matt.m_WindowHandle,12);
}

void MainWindow::resizeEvent(QResizeEvent *ev)
{
    if (matt.m_WindowHandle != NULL)
    {
        SetWindowExtents(matt.m_WindowHandle, 0, 0, ui->image->width(), ui->image->height());
    }
}

void MainWindow::updateImage(HalconCpp::HObject image)
{
    HalconCpp::ClearWindow(matt.m_WindowHandle);
    DispObj(image, matt.m_WindowHandle);
    ui->image->m_currentImg = image;
    ui->image->m_hHalconID = matt.m_WindowHandle;
}
void MainWindow::updateregion(HalconCpp::HObject region)
{
    HalconCpp::ClearWindow(matt.m_WindowHandle);
    DispObj(region, matt.m_WindowHandle);
    ui->image->m_currentImg = region;
    ui->image->m_hHalconID = matt.m_WindowHandle;
}

void MainWindow::okNg(bool judge)
{
    if(judge){
        ui->erro->setText("O K");
        ui->erro->setStyleSheet("QLabel{background:#00ff00;}");
    }else{
        ui->erro->setText("N G");
        ui->erro->setStyleSheet("QLabel{background:#ff0000;}");
    }
}


void MainWindow::on_dktp_clicked()
{
    okNg(true);
    try {
        //打开选择文件对话框，选择文件
            QString qtFilePath = QFileDialog::getOpenFileName(this, "选择图片", "./", "图像文件(*.jpg *.png *.bmp *.tif)");
            if (qtFilePath.isEmpty()){
                return;
            }
            QFileInfo fileInfo(qtFilePath);
            qtFilePath.replace("/", "\\");
            QString hPath = fileInfo.path().replace("/", "\\");
            //由halcon算子获取选中的文件夹中的所有文件
            ListFiles(hPath.toStdString().c_str(), "files", &matt.m_imgFiles);
            //筛选符合图片格式的文件
            TupleRegexpSelect(matt.m_imgFiles, HalconCpp::HTuple("\\.(jpg|png|bmp|tif)$").Append("ignore_case"), &matt.m_imgFiles);
            //找到选择的文件
            TupleFind(matt.m_imgFiles, qtFilePath.toStdString().c_str(), &matt.index);
            //读取图像
            ReadImage(&matt.m_image, HalconCpp::HTuple(matt.m_imgFiles[matt.index]));
            showImg();
            matt.m_hResizedImg = matt.m_image;
            matt.updateImage = matt.m_hResizedImg;
    } catch (HalconCpp::HException& e) {
        okNg(false);
    }
}

void MainWindow::on_hdh_clicked()
{
    ui->listWidget->addItem("灰度化-"+QString::number(matt.domCount++));
    matt.domVector.append(new Rgb1ToGrayDom());
}

void MainWindow::on_ezh_clicked()
{
    ui->listWidget->addItem("二值化-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomThreshold());
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString value = item->text();
    QStringList strList = value.split("-");
    QString values = strList[0];
    int key = strList[1].toInt();
    matt.Index = key;
    matt.domVector.at(key)->image = matt.m_hResizedImg;
    if(values.contains("绘制")){
         matt.domVector.at(key)->windowHandle = matt.m_WindowHandle;
         ui->image->m_drawRoiJudge=false;
         matt.domVector.at(key)->action();
         ui->image->m_drawRoiJudge=true;
         matt.updateImage =  matt.domVector.at(key)->ImageOrReduced;
         updateImage(matt.updateImage);
    }else    if(values=="二值化"){
        td->init();
        td->exec();
        updateregion(matt.updateregion);
    }else if(values=="对比度"){
        sd->init();
        sd->exec();
        updateImage(matt.updateImage);
    }else if(values=="腐蚀"){
        ecd->init();
        ecd->exec();
        updateregion(matt.updateregion);
    }else if(values=="膨胀"){
        dd->init();
        dd->exec();
        updateregion(matt.updateregion);
    }else if(values=="闭运算"){
        cd->init();
        cd->exec();
        updateregion(matt.updateregion);
    }else if(values=="开运算"){
        od->init();
        od->exec();
        updateregion(matt.updateregion);
    }else if(values=="连通域"){
        matt.domVector.at(key)->image = matt.updateregion;
        matt.domVector.at(key)->action();
        matt.updateregion = matt.domVector.at(key)->ImageOrReduced;
        updateregion(matt.updateregion);
    }else if(values=="特征选型"){
        selectd->init();
        selectd->exec();
    }else if(values=="创建模板"){
        cssmd->init();
        cssmd->exec();
    }else{
        matt.domVector.at(key)->action();
        matt.updateImage = matt.domVector.at(key)->ImageOrReduced;
        updateImage(matt.updateImage);
    }
}

void MainWindow::on_pushButton_clicked()
{
}

void MainWindow::on_jx_clicked()
{
    ui->listWidget->addItem("绘制矩形-"+QString::number(matt.domCount++));
    matt.domVector.append(new DrawRoiQhRectangle1());
}

void MainWindow::on_xzjx_clicked()
{
    ui->listWidget->addItem("绘制旋转矩形-"+QString::number(matt.domCount++));
    matt.domVector.append(new DrawRoiQhRectangle2());
}

void MainWindow::on_yx_clicked()
{
    ui->listWidget->addItem("绘制圆形-"+QString::number(matt.domCount++));
    matt.domVector.append(new DrawRoiQhCircle());
}

void MainWindow::on_ty_clicked()
{
    ui->listWidget->addItem("绘制椭圆-"+QString::number(matt.domCount++));
    matt.domVector.append(new DrawRoiQhEllipse());
}

void MainWindow::on_dbd_clicked()
{
    ui->listWidget->addItem("对比度-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomScaleImage());
}

void MainWindow::on_fs_clicked()
{
    ui->listWidget->addItem("腐蚀-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomErosionCircle());
}

void MainWindow::on_pz_clicked()
{
    ui->listWidget->addItem("膨胀-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomDilation());
}

void MainWindow::on_bys_clicked()
{
    ui->listWidget->addItem("闭运算-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomClosing());
}

void MainWindow::on_kys_clicked()
{
    ui->listWidget->addItem("开运算-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomOpening());
}

void MainWindow::on_lty_clicked()
{
    ui->listWidget->addItem("连通域-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomConnection());
}

void MainWindow::on_tzxx_clicked()
{
    ui->listWidget->addItem("特征选型-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomSelectShape());
}

void MainWindow::on_cjmb_clicked()
{
    ui->listWidget->addItem("创建模板-"+QString::number(matt.domCount++));
    matt.domVector.append(new DomCreateScaledShapeModel());
}
