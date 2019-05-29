#ifndef _MYVIDEOWIDGET_H_
#define _MYVIDEOWIDGET_H_
#include <QtGui>
#include <QtWidgets/qwidget.h>
#include <qwidgetresizehandler_p.h>
#include <qmediaplayer.h>
#include <qvideowidget.h>
#include <qlabel.h>
#include <QTimer>
#include "FireSlider.h"

class MyVideoWidget :public QVideoWidget
{
	Q_OBJECT
public:
	explicit MyVideoWidget(QWidget* parent = 0);
	~MyVideoWidget();
	void SetMediaPlayer(QMediaPlayer* player);
	void SetSlider(FireSlider* Vs);
	void SetLabel(QLabel* Vps, QLabel* Vpss);
protected:
	void keyPressEvent(QKeyEvent* event); //键盘输入事件
	void mousePressEvent(QMouseEvent* event); //屏幕单击事件
	void mouseDoubleClickEvent(QMouseEvent *event); //屏幕双击事件
	void enterEvent(QEvent *event); //鼠标进入事件
	void leaveEvent(QEvent *event);//鼠标离开事件
	void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
	//void contextMenuEvent(QContextMenuEvent *event);
	private slots:
	void TimeSlot();
private:
	FireSlider* MiniPlaySlider; //
	QLabel* MiniPlaySchedule;
	QLabel* MiniPlaySumSchedule;
	QMediaPlayer* ThePlayer; //与主窗口player同步
	QTimer* timer;
};


#endif