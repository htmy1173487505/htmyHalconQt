#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include "mainwindowatt.h"
#include "dialogFile/thresholddialog.h"
#include "dialogFile/scaleimagedialog.h"
#include "dialogFile/erosioncircledialog.h"
#include "dialogFile/dilationdialog.h"
#include "dialogFile/closiongdialog.h"
#include "dialogFile/openingdialog.h"
#include "dialogFile/selectdialog.h"
#include "dialogFile/createscaledshapemodeldialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    //初始化
    void init();
    //打开窗口
    void showImg();
    //窗体大小改变事件
    void resizeEvent(QResizeEvent *ev);
private slots:
    void on_dktp_clicked();
    void on_hdh_clicked();
    void on_ezh_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_clicked();
    void on_jx_clicked();
    void on_dbd_clicked();
    void on_xzjx_clicked();
    void on_yx_clicked();
    void on_ty_clicked();
    void on_fs_clicked();
    void on_pz_clicked();
    void on_bys_clicked();
    void on_kys_clicked();
    void on_lty_clicked();
    void on_tzxx_clicked();
    
    void on_cjmb_clicked();

public:
    void updateImage(HalconCpp::HObject image);
    void updateregion(HalconCpp::HObject region);
    void okNg(bool judge);
private:
    Ui::MainWindow *ui;
    MainWindowAtt matt;
    ThresholdDialog* td;
    ScaleimageDialog* sd;
    ErosionCircleDialog* ecd;
    DilationDialog* dd;
    ClosiongDialog* cd;
    OpeningDialog* od;
    SelectDialog* selectd;
    CreateScaledShapeModelDialog* cssmd;
};

#endif // MAINWINDOW_H
