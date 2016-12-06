#include <afxwin.h>
#include <string>
// afx_msg - объ€вление обработчика сообщений

int counterOfWords = 0;
int statusOfTimer = 1;
int TimerID = 1;

class CMyMainWnd : public CFrameWnd { // задаЄт главное окно приложени€
	int positionX, positionY;
	int key;
	CString str[5];
	CBrush* brush;
public:
	CMyMainWnd()
	{
		Create(NULL, L"Laboratory work");
		positionX = 100;
		positionY = 200;
		str[0] = "This is";
		str[1] = "lab";
		str[2] = "work";
		str[3] = "on";
		str[4] = "programming!!!";
	}
	afx_msg void OnTimer(UINT)
	{
		static int i = 0;
		CClientDC dc(this);
		dc.SetTextColor(RGB(rand() % 255, rand() % 255, rand() % 255));
		//dc.TextOutW(positionX, positionY, str[i]);
		CFont font;
		font.CreateFont(40, 20, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, VARIABLE_PITCH | FF_DONTCARE, L"Arial");
		CFont *pFont = dc.SelectObject(&font);
		dc.TextOut(positionX , positionY, str[i]);
		dc.SelectObject(&font);
		counterOfWords++;
		positionX += 150;
		i++;
		if (counterOfWords == 5)
		{
			positionX = 100;
			positionY = 300;
			counterOfWords = 0;
			KillTimer(TimerID);
			statusOfTimer = 0;
			TimerID++;
			i = 0;
		}
	}
	afx_msg void OnLButtonDown(UINT, CPoint)
	{
		key = -1;

		Invalidate(); // фон уничтожаетс€
	}
	afx_msg void OnRButtonDown(UINT, CPoint)
	{
		SetTimer(TimerID, 3000, NULL);
	}
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		switch (nChar) {
		case 49:
			key = 1;
			brush = new CBrush(RGB(10, 255, 85));
			Invalidate();
			break;
		case 50:
			key = 2;
			brush = new CBrush(RGB(250, 125, 11));
			Invalidate();
			break;
		case 51:
			key = 3;
			brush = new CBrush(RGB(150, 0, 0));
			Invalidate();
			break;
		case 52:
			key = 4;
			brush = new CBrush(RGB(50, 255, 255));
			Invalidate();
			break;
		case 53:
			key = 5;
			brush = new CBrush(RGB(190, 80, 99));
			Invalidate();
			break;
		case 54:
			key = 6;
			brush = new CBrush(RGB(200, 200, 200));
			Invalidate();
			break;
		}
	}
	afx_msg void OnPaint()
	{
		// CPaintDC унаследован от CDC
		CPaintDC DC(this); // — помощью объекта класса CPaintDC отображаем фигуры в окне
		DC.SelectObject(brush); // выбирает перо
		switch (key) 
		{
		case 1: // окружность
			DC.Ellipse(70, 70, 200, 200);
			break;
		case 2: // эллипс
			DC.Ellipse(220, 220, 50, 150);
			break;
		case 3: // пр€моугольник
			DC.Rectangle(20, 50, 100, 100);
			break;
		case 4: // квадрат
			DC.Rectangle(100, 100, 150, 150);
			break;
		case 5: // сектор
			DC.Pie(300, 350, 400, 150, 300, 50, 300, 150);
			break;
		case 6: // сегмент
			DC.Chord(20, 20, 226, 144, 202, 115, 105, 32);
		}
	}
	~CMyMainWnd()
	{
		if (!statusOfTimer)
			KillTimer(TimerID);
	}
	DECLARE_MESSAGE_MAP() // макрос, с помощью которого класс будет реагировать на сообщени€
};

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd) // (дл€ какого класса пишем карту сообщений, кто должен обрабатывать сообщение)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

class CMyApp : public CWinApp // само приложение
{
public:
	CMyApp() {};
	virtual BOOL InitInstance()
	{
		m_pMainWnd = new CMyMainWnd(); // экземпл€р главного окна
		m_pMainWnd->ShowWindow(SW_SHOW); // созданное окно отображаетс€ на экран
		return TRUE;
	}
};

CMyApp theApp;