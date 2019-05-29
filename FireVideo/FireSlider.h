#ifndef _FIRESLIDER_H_
#define _FIRESLIDER_H_
#include <qslider.h>
#include <qwidget.h>
#include <qevent.h>
#include <qwidgetresizehandler_p.h>
#include <qmediaplayer.h>
class FireSlider : public QSlider
{
	Q_OBJECT
public:
	FireSlider(QWidget* parent = 0);
	~FireSlider();
	void SetItPlayer(QMediaPlayer* player);
private:
	//void mouseMoveEvent(QMouseEvent *ev);
	void enterEvent(QEvent *event); //鼠标进入事件
	void mouseReleaseEvent(QMouseEvent *ev);
	QMediaPlayer* ThePlayer;
};


#endif