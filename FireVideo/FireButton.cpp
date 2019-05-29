#include "FireButton.h"
FireButton::FireButton(QWidget *parent) :QPushButton(parent)
{
	hintOpenfile = new QLabel();
	setMouseTracking(true);    //ʹ���δ�����ƶ�����£�Ҳ�ɴ���mouseMoveEvent
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
	ButtonPos = hintOpenfile->pos(); //��ȡ�������������е����λ������
	QString text = hintOpenfile->text();
	Text_Size = text.size();
}
void FireButton::enterEvent(QEvent *event) //û��FocusIconͼƬ�ķŴ�ͼ�꣬��ʾ����
{
	CursorPos = cursor().pos(); //�������λ��,�����������Ļ������
	CursorPos = mapFromGlobal(QCursor::pos());//תΪ����ڿؼ��������
	int posx = CursorPos.x() + ButtonPos.x() + 15;//��ǩ����Ժᡢ�����꣬��������СQsize(15,25);
	int posy = CursorPos.y() + ButtonPos.y() + 25;
	if ((posx + 15 * Text_Size) > 400)   //��ǩ��ʾ���������淶Χ
		posx = 400 - 15 * Text_Size;
	hintOpenfile->setGeometry(QRect(posx, posy, 25 * Text_Size, 30));
	hintOpenfile->setVisible(true);
	if (!FocusIcon.isNull())
		setIcon(FocusIcon);
	else
		setIconSize(QSize(45, 45)); //�޾۽�ͼƬ��ͼƬ�Ŵ�
}
void FireButton::mouseMoveEvent(QMouseEvent *e)
{
	QPoint CursorPos = e->pos();
	qint32 posx = CursorPos.x() + ButtonPos.x() + 15;//��ǩ����Ժᡢ�����꣬��������СQsize(15,25);
	qint32 posy = CursorPos.y() + ButtonPos.y() + 25;
	if ((posx + 15 * Text_Size) > 400)   //��ǩ��ʾ���������淶Χ
		posx = 400 - 15 * Text_Size;
	hintOpenfile->setGeometry(QRect(posx, posy, 25 * Text_Size, 30)); 
	hintOpenfile->setVisible(true);
}
void FireButton::leaveEvent(QEvent *event)
{
	hintOpenfile->setVisible(false);
	if (!NormalIcon.isNull())
		setIcon(NormalIcon);
	if (FocusIcon.isNull()) //�޾۽�ͼƬ����ԭԭ���ߴ�
		setIconSize(QSize(35, 35));
}