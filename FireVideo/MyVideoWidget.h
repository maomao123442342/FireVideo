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
	void keyPressEvent(QKeyEvent* event); //���������¼�
	void mousePressEvent(QMouseEvent* event); //��Ļ�����¼�
	void mouseDoubleClickEvent(QMouseEvent *event); //��Ļ˫���¼�
	void enterEvent(QEvent *event); //�������¼�
	void leaveEvent(QEvent *event);//����뿪�¼�
	void mouseMoveEvent(QMouseEvent *event);//����ƶ��¼�
	//void contextMenuEvent(QContextMenuEvent *event);
	private slots:
	void TimeSlot();
private:
	FireSlider* MiniPlaySlider; //
	QLabel* MiniPlaySchedule;
	QLabel* MiniPlaySumSchedule;
	QMediaPlayer* ThePlayer; //��������playerͬ��
	QTimer* timer;
};


#endif