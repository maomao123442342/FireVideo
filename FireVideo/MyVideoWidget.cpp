#include "MyVideoWidget.h"

MyVideoWidget::MyVideoWidget(QWidget* parent) :QVideoWidget(parent)
{
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimeSlot()));
	setMouseTracking(true);    //ʹ���δ�����ƶ�����£�Ҳ�ɽ���mouseMoveEvent
	//connect(this, SIGNAL(fullScreenChanged(bool)), this, SLOT(FullScreenChangedSlot(bool isFull)));
}
MyVideoWidget::~MyVideoWidget()
{

}

void MyVideoWidget::SetMediaPlayer(QMediaPlayer* player)
{
	ThePlayer = player;
}
void MyVideoWidget::SetSlider(FireSlider* Vs)
{
	MiniPlaySlider = Vs;
}
void MyVideoWidget::SetLabel(QLabel* Vps, QLabel* Vpss)
{
	MiniPlaySchedule = Vps;
	MiniPlaySumSchedule = Vpss;
}

void MyVideoWidget::TimeSlot()
{
	if (ThePlayer->state() == QMediaPlayer::PausedState)
		return;
	else{
		MiniPlaySlider->setVisible(false);
		MiniPlaySchedule->setVisible(false);
		MiniPlaySumSchedule->setVisible(false);
	}
}

void MyVideoWidget::keyPressEvent(QKeyEvent* event)
{
	if ((event->key() == Qt::Key_Escape) && (isFullScreen())) //�����¼���ESC�˳�ȫ��ģʽ
	{
		setWindowFlags(Qt::FramelessWindowHint); //��Ϊ�Ӵ���
		move(0, 30);
		resize(450, 400);
		setVisible(true);
		MiniPlaySlider->raise();
		MiniPlaySchedule->raise();
		MiniPlaySumSchedule->raise();
		timer->start(5000); //�򿪶�ʱ��
	}
	QVideoWidget::keyPressEvent(event);
}
void MyVideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (!isFullScreen())
	{
		setWindowFlags(Qt::Window);
		setFullScreen(true);
		timer->stop();  //ȫ��״̬�¹رն�ʱ��
	}
	else
	{
		setWindowFlags(Qt::FramelessWindowHint); //��Ϊ�Ӵ���
		move(0, 30);
		resize(450, 400);
		setVisible(true);
		MiniPlaySlider->raise();
		MiniPlaySchedule->raise();
		MiniPlaySumSchedule->raise();
		timer->start(5000); //�򿪶�ʱ��
	}
	QVideoWidget::mouseDoubleClickEvent(event);
}
void MyVideoWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) //��Ļ�ϵ���������pause/play
	{
		if (ThePlayer->state() == QMediaPlayer::PlayingState){
			ThePlayer->pause();
		}
		else
			ThePlayer->play();
	}
	QVideoWidget::mousePressEvent(event);
}

void MyVideoWidget::enterEvent(QEvent *event)
{
	MiniPlaySlider->setVisible(true);
	MiniPlaySchedule->setVisible(true);
	MiniPlaySumSchedule->setVisible(true);
}
void MyVideoWidget::leaveEvent(QEvent *event)
{

}
void MyVideoWidget::mouseMoveEvent(QMouseEvent *event)
{
	MiniPlaySlider->setVisible(true);
	MiniPlaySchedule->setVisible(true);
	MiniPlaySumSchedule->setVisible(true);
	timer->start(5000); //5s�����û���ƶ����������ؽ������ȿؼ�
}
