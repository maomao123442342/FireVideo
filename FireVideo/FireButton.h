#ifndef _FIREBUTTON_H_
#define _FIREBUTTON_H_
#include <QtGui>
#include <QtWidgets>
#include <qwidgetresizehandler_p.h>

class FireButton :public QPushButton
{
	Q_OBJECT
public:
	FireButton(QWidget *parent = Q_NULLPTR);
	~FireButton();
	void Input_Button_Icon(QIcon& N, QIcon& F = QIcon(), QIcon& P = QIcon()); //���ð�������״̬ͼ��,FocusIcon/PressIconĬ������¾�Ϊ����ͼ��
	void Set_HintInfo(QLabel* info); //���ý��밴������ʾ��Ϣ,Ĭ��
protected:
	void enterEvent(QEvent *event); //�������¼�
	void leaveEvent(QEvent *event);//����뿪�¼�
	//void mousePressEvent(QMouseEvent* event); //��Ļ�����¼�
	void mouseMoveEvent(QMouseEvent *e); //����ƶ�
	//void mouseDoubleClickEvent(QMouseEvent *event); //��Ļ˫���¼�
private:
	QIcon NormalIcon;
	QIcon FocusIcon;
	QIcon PressIcon;
	QLabel* hintOpenfile;
	QPoint CursorPos;//���λ�õ�
	QPoint ButtonPos;//�������������е�λ��
	qint16 Text_Size; //��ʾ���ֵĴ�С
};

#endif