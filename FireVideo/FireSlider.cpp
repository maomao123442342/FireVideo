#include "FireSlider.h"
FireSlider::FireSlider(QWidget* parent)
{
	
}
FireSlider::~FireSlider()
{

}
void FireSlider::SetItPlayer(QMediaPlayer* player)
{
	ThePlayer = player;
}

void FireSlider::mouseReleaseEvent(QMouseEvent *ev)
{
	QPointF Qpint = ev->localPos();
	int posx = Qpint.x();
	qint64 dur = ThePlayer->duration(); //当前视频总时长
	qint16 Length = size().width();
	int p = posx*dur / Length;
	int cur = ThePlayer->position();//播放器当前位置
	if (cur >(p - (dur / 69)) && cur <(p + (dur / 69))) //点击位置在当前位置附近处，不改变播放位置
		return;
	setValue(p);
	ThePlayer->setPosition(p);
	QSlider::mouseReleaseEvent(ev);
}

void FireSlider::enterEvent(QEvent *event)
{

}
