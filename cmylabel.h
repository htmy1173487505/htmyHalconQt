#pragma once

#include <QLabel>
#include <QWheelEvent>
#include"HalconCpp.h"
using namespace HalconCpp;
# pragma execution_character_set("utf-8")
class CMyLabel : public QLabel
{
    Q_OBJECT

public:
    CMyLabel(QWidget *parent = Q_NULLPTR);
    ~CMyLabel();

    //设置Halcon图像和Halcon窗口句柄，用户响应鼠标事件后实时更新图像
    void setHalconWnd(HObject img, HTuple hHalconID, QLabel *label);
    //鼠标滚轮缩放事件
    void wheelEvent(QWheelEvent *ev);
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *ev);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev);
    Herror Hee (HTuple &mouseRow, HTuple&mouseCol, HTuple&Button);
public:
    HTuple m_labelID;			//Qt标签句柄
    HTuple m_hHalconID;			//Halcon窗口句柄
    HObject m_currentImg;		//当前的图像
    //主界面显示坐标的标签
    QLabel *m_label;
    //鼠标按下的位置
    HTuple m_tMouseDownRow;
    HTuple m_tMouseDownCol;
    bool m_bIsMove;				//是否移动图像标识
    bool m_drawRoiJudge;    //绘制ROI时不准移动
};
