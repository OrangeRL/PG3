#include "DxLib.h"
#include "Enemy.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2B_16_Nauldee_Nawill";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み
	Enemy* enemy1 = Enemy::GetInstance();
	Enemy* enemy2 = Enemy::GetInstance();
	Enemy* enemy3 = Enemy::GetInstance();
	Enemy* enemy4 = Enemy::GetInstance();
	Enemy* enemy5 = Enemy::GetInstance();
	Enemy* enemy6 = Enemy::GetInstance();
	Enemy* enemy7 = Enemy::GetInstance();
	Enemy* enemy8 = Enemy::GetInstance();
	Enemy* enemy9 = Enemy::GetInstance();
	Enemy* enemy10 = Enemy::GetInstance();

	// ゲームループで使う変数の宣言


	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (1)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		if (keys[KEY_INPUT_SPACE] == true && oldkeys[KEY_INPUT_SPACE] == false)
		{
			enemy1->Dead();
		}

		// 描画処理
		enemy1->Draw(100, 100);
		enemy2->Draw(200, 100);
		enemy3->Draw(300, 100);
		enemy4->Draw(400, 100);
		enemy5->Draw(100, 200);
		enemy6->Draw(200, 200);
		enemy7->Draw(300, 200);
		enemy8->Draw(400, 200);
		enemy9->Draw(500, 100);
		enemy10->Draw(500, 200);


		DrawString(250, 350, "スペース", GetColor(255, 255, 0));

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}