#include<stdio.h>
#include<CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
#ifdef _MSV_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable: 4996)

int main()
{
	// 건물이 들어갈 정육면체의 두점을 입력받는다
	int sx, sy, sz, ex, ey, ez;
	printf("한점을 입력하세요");
	scanf_s("%d %d %d", &sx, &sy, &sz);
	printf("나머지 한 점을 입력하세요");
	scanf_s("%d %d %d", &ex, &ey, &ez);
	//건축물 제작에 사용할 블록 생성
	WoolID wool2 = createWool(COLOR_WHITE);
	WoolID wool = createWool(COLOR_BLACK);
	WoolID wool3 = createWool(COLOR_RED);
	//입력받은 위치값을 복사
	int sa = sx, sb = sy, sc = sz, ea = ex, eb = ey, ec = ez;
	int a = 0;

	//가늠쇠 만들기
	locateBlock(wool3, (ea+sa)/2, (eb+sb)/2, (ec+sc)/2);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2)+1, ((ec + sc) / 2)+1);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2) + 1, ((ec + sc) / 2) - 1);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2) - 1, ((ec + sc) / 2) + 1);
	locateBlock(wool2, (ea + sa) / 2, ((eb + sb) / 2) - 1, ((ec + sc) / 2) - 1);
	//입력 크기에 따라 변할 가슴쇠 테두리
		// y값 감소
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
		// z값 감소
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
		//두 값 역전
		sa = ex, sb = ey, sc = ez, ea = sx, eb = sy, ec = sz;
		if (ex > sx)sa = ex - a;
		if (ex < sx)ea = sx - a;
		// z값 감소
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
		//y값 감소
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
		//변수 초기화 
		sa = sx, sb = sy, sc = sz, ea = ex, eb = ey, ec = ez;
		a++;
		if(ex>sx)ea = ex -a;
		if(ex<sx)sa = sx - a;

	}

}