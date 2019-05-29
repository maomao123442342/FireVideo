#include "MyVideoWidget.h"

MyVideoWidget::MyVideoWidget(QWidget* parent) :QVideoWidget(parent)
{
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimeSlot()));
	setMouseTracking(true);    //使鼠标未按下移动情况下，也可进入mouseMoveEvent
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
	if ((event->key() == Qt::Key_Escape) && (isFullScreen())) //按键事件，ESC退出全屏模式
	{
		setWindowFlags(Qt::FramelessWindowHint); //设为子窗口
		move(0, 30);
		resize(450, 400);
		setVisible(true);
		MiniPlaySlider->raise();
		MiniPlaySchedule->raise();
		MiniPlaySumSchedule->raise();
		timer->start(5000); //打开定时器
	}
	QVideoWidget::keyPressEvent(event);
}
void MyVideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (!isFullScreen())
	{
		setWindowFlags(Qt::Window);
		setFullScreen(true);
		timer->stop();  //全屏状态下关闭定时器
	}
	else
	{
		setWindowFlags(Qt::FramelessWindowHint); //设为子窗口
		move(0, 30);
		resize(450, 400);
		setVisible(true);
		MiniPlaySlider->raise();
		MiniPlaySchedule->raise();
		MiniPlaySumSchedule->raise();
		timer->start(5000); //打开定时器
	}
	QVideoWidget::mouseDoubleClickEvent(event);
}
void MyVideoWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) //屏幕上单击鼠标左键pause/play
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
	timer->start(5000); //5s内鼠标没有移动操作则隐藏进度条等控件
}
