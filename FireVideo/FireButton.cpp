#include "FireButton.h"
FireButton::FireButton(QWidget *parent) :QPushButton(parent)
{
	hintOpenfile = new QLabel();
	setMouseTracking(true);    //使鼠标未按下移动情况下，也可触发mouseMoveEvent
	setFocusPolicy(Qt::NoFocus);
}

FireButton::~FireButton()
{

}
void FireButton::Input_Button_Icon(QIcon& N, QIcon& F, QIcon& P)
{
	NormalIcon = N;
	FocusIcon = F;
	PressIcon = P;
	setIcon(NormalIcon);
}
void FireButton::Set_HintInfo(QLabel* HintLable)
{
	hintOpenfile = HintLable;
	ButtonPos = hintOpenfile->pos(); //获取按键在主界面中的相对位置坐标
	QString text = hintOpenfile->text();
	Text_Size = text.size();
}
void FireButton::enterEvent(QEvent *event) //没有FocusIcon图片的放大图标，表示进入
{
	CursorPos = cursor().pos(); //光标所处位置,相对于整个屏幕的坐标
	CursorPos = mapFromGlobal(QCursor::pos());//转为相对于控件的坐标点
	int posx = CursorPos.x() + ButtonPos.x() + 15;//标签的相对横、纵坐标，其中鼠标大小Qsize(15,25);
	int posy = CursorPos.y() + ButtonPos.y() + 25;
	if ((posx + 15 * Text_Size) > 400)   //标签显示超出主界面范围
		posx = 400 - 15 * Text_Size;
	hintOpenfile->setGeometry(QRect(posx, posy, 25 * Text_Size, 30));
	hintOpenfile->setVisible(true);
	if (!FocusIcon.isNull())
		setIcon(FocusIcon);
	else
		setIconSize(QSize(45, 45)); //无聚焦图片，图片放大
}
void FireButton::mouseMoveEvent(QMouseEvent *e)
{
	QPoint CursorPos = e->pos();
	qint32 posx = CursorPos.x() + ButtonPos.x() + 15;//标签的相对横、纵坐标，其中鼠标大小Qsize(15,25);
	qint32 posy = CursorPos.y() + ButtonPos.y() + 25;
	if ((posx + 15 * Text_Size) > 400)   //标签显示超出主界面范围
		posx = 400 - 15 * Text_Size;
	hintOpenfile->setGeometry(QRect(posx, posy, 25 * Text_Size, 30)); 
	hintOpenfile->setVisible(true);
}
void FireButton::leaveEvent(QEvent *event)
{
	hintOpenfile->setVisible(false);
	if (!NormalIcon.isNull())
		setIcon(NormalIcon);
	if (FocusIcon.isNull()) //无聚焦图片，还原原来尺寸
		setIconSize(QSize(35, 35));
}