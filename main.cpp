////==========================================
//Matrix4型のテスト
//==========================================
#include"Vector3.h"
#include"Matrix4.h"
#include<DxLib.h>
#include<cstring>
#include <cmath>
//memcpy//球(Sphere)の描画
//DxLib=>intDrawSphere3D(VECTORCenterPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag);

//円錐(Cone)の描画
//DxLib=>intDrawCone3D(VECTORTopPos,VECTORBottomPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
int DrawCone3D(const Vector3& TopPos, const Vector3& BottomPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag);

//線分の描画
//DxLib=>intDrawLine3D(VECTORPos1,VECTORPos2,unsignedintColor);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color);

//カメラの位置と姿勢の設定
//DxLib=>intSetCameraPositionAndTargetAndUpVec(VECTORPosition,VECTORTarget,VECTORUp);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,	//カメラの位置
	const Vector3& cameraTarget,	//カメラの注視点
	const Vector3& cameraUp			//カメラの上の向き
);

//モデルの座標変換用行列をセットする
//DxLib=>intMV1SetMatrix(intMHandle,MATRIXMatrix);
int MV1SetMatrix(const int MHandle, const Matrix4 Matrix);
//関数プロトタイプ宣言
void DrawAxis3D(const float length);	//x,y,z軸の描画
void DrawKeyOperation();				//キー操作の描画

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//DxLib初期化
	const int WindowWidth = 1024;
	const int WindowHeight = 576;

	ChangeWindowMode(TRUE);							//ウインドウモードにする
	SetGraphMode(WindowWidth, WindowHeight, 32);	//画面モードのセット
	SetBackgroundColor(0, 0, 64);					//背景色RGB 
	if (DxLib_Init() == -1)return-1;				//DxLib 初期化処理
	SetDrawScreen(DX_SCREEN_BACK);					//描画先画面を裏画面にセット

	SetUseZBuffer3D(TRUE);							//Ｚバッファを有効にする
	SetWriteZBuffer3D(TRUE);						//Ｚバッファへの書き込みを有効にする

	//カメラ初期化
	Vector3 cameraPosition(50.0f, 50.0f, -400.0f);
	Vector3 cameraTarget(0.0f, 0.0f, 0.0f);
	Vector3 cameraUp(0.0f, 1.0f, 0.0f);

	//クリップ面		近		遠
	SetCameraNearFar(1.0f, 1000.0f);//カメラの有効範囲を設定
	SetCameraScreenCenter(WindowWidth / 2.0f, WindowHeight / 2.0f);//画面の中心をカメラの中心に合わせる
	SetCameraPositionAndTargetAndUpVec(
		Vector3(0.0f, 0.0f, -120.0f),//カメラの位置
		//Vector3(-20.0f,20.0f,-120.0f),//カメラの位置
		Vector3(0.0f, 0.0f, 0.0f),//カメラの注視点
		Vector3(0.0f, 1.0f, 0.0f));//カメラの上の向き

	//Circle
	float circleX = 10;
	float circleY = 10;
	float circleR = 30;

	//Line
	float lineX1 = 100;
	float lineY1 = 300;
	float lineX2 = 500;
	float lineY2 = 100;
	
	//Line length
	float distX = lineX1 - lineX2;
	float distY = lineY1 - lineY2;
	float len = sqrt((distX * distX) + (distY * distY));
	
	//Dot product of the line and circle
	float dot = (((circleX - lineX1) * (lineX2 - lineX1)) + ((circleY - lineY1) * (lineY2 - lineY1))) / pow(len, 2);

	float closestX = lineX1 + (dot * (lineX2 - lineX1));
	float closestY = lineX1 + (dot * (lineY2 - lineY1));
	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//更新---------------------------
		if (CheckHitKey(KEY_INPUT_S))circleY += 1;
		if (CheckHitKey(KEY_INPUT_D))circleX += 1;
		if (CheckHitKey(KEY_INPUT_W))circleY -= 1;
		if (CheckHitKey(KEY_INPUT_A))circleX -= 1;

		distX = closestX - circleX;
		distY = closestY - circleY;
		float distance = sqrt((distX * distX) + (distY * distY));
		
		//描画---------------------------
		ClearDrawScreen();
		//画面を消去
		//xyz軸の描画
		DrawAxis3D(500.0f);

		//モデルの描画
		if (distance >= circleR) {
		DrawCircle(circleX, circleY, circleR , GetColor(255, 255, 0), true);
		DrawLine(lineX1, lineY1 - 200, lineX2, lineY2 - 200, GetColor(255, 255, 0), true);
		}
		else if (distance <= circleR) {
		DrawCircle(circleX, circleY, circleR, GetColor(255, 0, 0), true);
		DrawLine(lineX1, lineY1-200, lineX2, lineY2-200, GetColor(255, 0, 0), true);
		}
		
		//DrawKeyOperation();	//キー操作の描画
		//フリップする
		ScreenFlip();
	}

	DxLib::DxLib_End();

	//DxLib終了処理
	return 0;
	//ソフトの終了
}
//xyz軸の描画
void DrawAxis3D(const float length)
{
	//軸の線の描画
	DrawLine3D(Vector3(-length, 0, 0), Vector3(+length, 0, 0), GetColor(255, 0, 0));	//x軸
	DrawLine3D(Vector3(0, -length, 0), Vector3(0, +length, 0), GetColor(0, 255, 0));	//y軸
	DrawLine3D(Vector3(0, 0, -length), Vector3(0, 0, +length), GetColor(0, 0, 255));	//z軸

	////軸の先の描画 xyz軸の先っぽに、円錐をつける
	//const float coneSize = 10.0f;
	//DrawCone3D(Vector3(length, 0, 0), Vector3(length - coneSize, 0, 0), coneSize / 2, 16,
	//	GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
	//DrawCone3D(Vector3(0, length, 0), Vector3(0, length - coneSize, 0), coneSize / 2, 16,
	//	GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
	//DrawCone3D(Vector3(0, 0, length), Vector3(0, 0, length - coneSize), coneSize / 2, 16,
	//	GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
}
//キー操作の描画
void DrawKeyOperation()
{
	const unsigned white = GetColor(255, 255, 255);
	DrawFormatString(10, 20 * 1, white, "[W][E][R]R:リセット");
	DrawFormatString(10, 20 * 2, white, "[A][S][D]AD:y軸まわりの回転");
	DrawFormatString(10, 20 * 3, white, "[Z]WS:x軸まわりの回転");
	DrawFormatString(10, 20 * 4, white, "EZ:z軸まわりの回転");

}

//以降、DxLibの各関数でVector3型Matrix4型を利用できるようにする関数群//球の描画//DxLib=>intDrawSphere3D(VECTORCenterPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag)
{
	VECTOR centerPos = { CenterPos.x,CenterPos.y,CenterPos.z };	//構造体初期化子リスト

	return DrawSphere3D(centerPos, r, DivNum, DifColor, SpcColor, FillFlag);
}

//DxLib=>intDrawCone3D(VECTORTopPos,VECTORBottomPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
int DrawCone3D(const Vector3& TopPos, const Vector3& BottomPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag)
{
	VECTOR topPos = { TopPos.x,TopPos.y,TopPos.z };
	VECTOR bottomPos = { BottomPos.x,BottomPos.y,BottomPos.z };
	return DrawCone3D(topPos, bottomPos, r, DivNum, DifColor, SpcColor, FillFlag);
}
//線分の描画//DxLib=>intDrawLine3D(VECTORPos1,VECTORPos2,unsignedintColor);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color)
{
	VECTOR p1 = { Pos1.x,Pos1.y,Pos1.z };//構造体初期化子リスト
	VECTOR p2 = { Pos2.x,Pos2.y,Pos2.z };//構造体初期化子リスト
	return DrawLine3D(p1, p2, Color);
}
//カメラの位置と姿勢の設定//DxLib=>intSetCameraPositionAndTargetAndUpVec(VECTORPosition,VECTORTarget,VECTORUp);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,//カメラの位置
	const Vector3& cameraTarget,//カメラの注視点
	const Vector3& cameraUp//カメラの上の向き
)
{
	VECTOR position = { cameraPosition.x,cameraPosition.y,cameraPosition.z };
	VECTOR target = { cameraTarget.x,cameraTarget.y,cameraTarget.z };
	VECTOR up = { cameraUp.x,cameraUp.y,cameraUp.z };
	return SetCameraPositionAndTargetAndUpVec(position, target, up);
}
//モデルの座標変換用行列をセットする
//DxLib=>intMV1SetMatrix(intMHandle,MATRIXMatrix);
int MV1SetMatrix(const int MHandle, const Matrix4 Matrix)
{
	MATRIX matrix; std::memcpy(&matrix, &Matrix, sizeof MATRIX);	//メモリ間コピー
	return MV1SetMatrix(MHandle, matrix);
}

