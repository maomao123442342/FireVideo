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
	qint64 dur = ThePlayer->duration(); //��ǰ��Ƶ��ʱ��
	qint16 Length = size().width();
	int p = posx*dur / Length;
	int cur = ThePlayer->position();//��������ǰλ��
	if (cur >(p - (dur / 69)) && cur <(p + (dur / 69))) //���λ���ڵ�ǰλ�ø����������ı䲥��λ��
		return;
	setValue(p);
	ThePlayer->setPosition(p);
	QSlider::mouseReleaseEvent(ev);
}

void FireSlider::enterEvent(QEvent *event)
{

}
