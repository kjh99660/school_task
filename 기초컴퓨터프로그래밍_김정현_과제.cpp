#include<stdio.h>
#include<CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
#ifdef _MSV_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable: 4996)

int main()
{
	// �ǹ��� �� ������ü�� ������ �Է¹޴´�
	int sx, sy, sz, ex, ey, ez;
	printf("������ �Է��ϼ���");
	scanf_s("%d %d %d", &sx, &sy, &sz);
	printf("������ �� ���� �Է��ϼ���");
	scanf_s("%d %d %d", &ex, &ey, &ez);
	//���๰ ���ۿ� ����� ��� ����
	WoolID wool2 = createWool(COLOR_WHITE);
	WoolID wool = createWool(COLOR_BLACK);
	WoolID wool3 = createWool(COLOR_RED);
	//�Է¹��� ��ġ���� ����
	int sa = sx, sb = sy, sc = sz, ea = ex, eb = ey, ec = ez;
	int a = 0;

	//���Ƽ� �����
	locateBlock(wool3, (ea+sa)/2, (eb+sb)/2, (ec+sc)/2);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2)+1, ((ec + sc) / 2)+1);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2) + 1, ((ec + sc) / 2) - 1);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2) - 1, ((ec + sc) / 2) + 1);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2) - 1, ((ec + sc) / 2) - 1);
	//�Է� ũ�⿡ ���� ���� ������ �׵θ�
		// y�� ����
	while (2*a < sx || 2*a < ex) {
		if (eb >= sb) {
			while (sb != eb) {
				locateBlock(wool, ea, eb, ec);
				eb--;
			}
		}
		if (sb >= eb) {
			while (sb != eb) {
				locateBlock(wool, sa, sb, sc);
				sb--;
			}
		}
		// z�� ����
		if (ec >= sc) {
			while (sc != ec) {
				locateBlock(wool, ea, eb, ec);
				ec--;
			}
		}
		if (sc >= ec) {
			while (sc != ec) {
				locateBlock(wool, sa, sb, sc);
				sc--;
			}
		}
		//�� �� ����
		sa = ex, sb = ey, sc = ez, ea = sx, eb = sy, ec = sz;
		if (ex > sx)sa = ex - a;
		if (ex < sx)ea = sx - a;
		// z�� ����
		if (ec >= sc) {
			while (sc != ec) {
				locateBlock(wool, ea, eb, ec);
				ec--;
			}
		}
		if (sc >= ec) {
			while (sc != ec) {
				locateBlock(wool, sa, sb, sc);
				sc--;
			}
		}
		//y�� ����
		if (eb >= sb) {
			while (sb != eb) {
				locateBlock(wool, ea, eb, ec);
				eb--;
			}
		}
		if (sb >= eb) {
			while (sb != eb) {
				locateBlock(wool, sa, sb, sc);
				sb--;
			}
		}
		//���� �ʱ�ȭ 
		sa = sx, sb = sy, sc = sz, ea = ex, eb = ey, ec = ez;
		a++;
		if(ex>sx)ea = ex -a;
		if(ex<sx)sa = sx - a;

	}

}