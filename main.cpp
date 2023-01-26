////==========================================
//Matrix4�^�̃e�X�g
//==========================================
#include"Vector3.h"
#include"Quaternion.h"
#include"Matrix4.h"
#include<DxLib.h>
#include<cstring>
#include <cmath>
//memcpy//��(Sphere)�̕`��
//DxLib=>intDrawSphere3D(VECTORCenterPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag);

//�~��(Cone)�̕`��
//DxLib=>intDrawCone3D(VECTORTopPos,VECTORBottomPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
int DrawCone3D(const Vector3& TopPos, const Vector3& BottomPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag);

//�����̕`��
//DxLib=>intDrawLine3D(VECTORPos1,VECTORPos2,unsignedintColor);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color);

void DrawString(float x, float y, int color, Quaternion q);
void Draw(int x, int y, Quaternion q);
Quaternion q1(2.0f, 3.0f, 4.0f, 1.0f);
Quaternion q2(1.0f, 3.0f, 5.0f, 2.0f);
//�P��Quaternion
Quaternion qIdentity = IdentityQuaternion();
//����
Quaternion conj = Conjugate(q1);
//�t
Quaternion inv = Inverse(q1);
//���K��
Quaternion normal = Normalize(q1);
//��
Quaternion mul1 = Multiply(q1, q2);
Quaternion mul2 = Multiply(q2, q1);
//norm 
float norm = Norm(q1);

Quaternion rotation0 = MakeAxisAngle({ 0.71f, 0.71f, 0.0f }, 0.3f);
Quaternion rotation1 = MakeAxisAngle({ -0.71f, -0.71f, -0.0f }, -0.3f);

Quaternion interpolate0 = Slerp(rotation0, rotation1, 0.0f);
Quaternion interpolate1 = Slerp(rotation0, rotation1, 0.3f);
Quaternion interpolate2 = Slerp(rotation0, rotation1, 0.5f);
Quaternion interpolate3 = Slerp(rotation0, rotation1, 0.7f);
Quaternion interpolate4 = Slerp(rotation0, rotation1, 1.0f);

//�J�����̈ʒu�Ǝp���̐ݒ�
//DxLib=>intSetCameraPositionAndTargetAndUpVec(VECTORPosition,VECTORTarget,VECTORUp);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,	//�J�����̈ʒu
	const Vector3& cameraTarget,	//�J�����̒����_
	const Vector3& cameraUp			//�J�����̏�̌���
);

//���f���̍��W�ϊ��p�s����Z�b�g����
//DxLib=>intMV1SetMatrix(intMHandle,MATRIXMatrix);
int MV1SetMatrix(const int MHandle, const Matrix4 Matrix);
//�֐��v���g�^�C�v�錾
void DrawAxis3D(const float length);	//x,y,z���̕`��
void DrawKeyOperation();				//�L�[����̕`��

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//DxLib������
	const int WindowWidth = 1024;
	const int WindowHeight = 576;

	ChangeWindowMode(TRUE);							//�E�C���h�E���[�h�ɂ���
	SetGraphMode(WindowWidth, WindowHeight, 32);	//��ʃ��[�h�̃Z�b�g
	SetBackgroundColor(0, 0, 64);					//�w�i�FRGB 
	if (DxLib_Init() == -1)return-1;				//DxLib ����������
	SetDrawScreen(DX_SCREEN_BACK);					//�`����ʂ𗠉�ʂɃZ�b�g

	SetUseZBuffer3D(TRUE);							//�y�o�b�t�@��L���ɂ���
	SetWriteZBuffer3D(TRUE);						//�y�o�b�t�@�ւ̏������݂�L���ɂ���

	//�J����������
	Vector3 cameraPosition(50.0f, 50.0f, -400.0f);
	Vector3 cameraTarget(0.0f, 0.0f, 0.0f);
	Vector3 cameraUp(0.0f, 1.0f, 0.0f);

	//�N���b�v��		��		��
	SetCameraNearFar(1.0f, 1000.0f);//�J�����̗L���͈͂�ݒ�
	SetCameraScreenCenter(WindowWidth / 2.0f, WindowHeight / 2.0f);//��ʂ̒��S���J�����̒��S�ɍ��킹��
	SetCameraPositionAndTargetAndUpVec(
		Vector3(0.0f, 0.0f, -120.0f),//�J�����̈ʒu
		//Vector3(-20.0f,20.0f,-120.0f),//�J�����̈ʒu
		Vector3(0.0f, 0.0f, 0.0f),//�J�����̒����_
		Vector3(0.0f, 1.0f, 0.0f));//�J�����̏�̌���

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
	//�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//�X�V---------------------------
		if (CheckHitKey(KEY_INPUT_S))circleY += 1;
		if (CheckHitKey(KEY_INPUT_D))circleX += 1;
		if (CheckHitKey(KEY_INPUT_W))circleY -= 1;
		if (CheckHitKey(KEY_INPUT_A))circleX -= 1;

		distX = closestX - circleX;
		distY = closestY - circleY;
		float distance = sqrt((distX * distX) + (distY * distY));

		//�`��---------------------------
		ClearDrawScreen();
		//��ʂ�����
		//xyz���̕`��
		DrawAxis3D(500.0f);

		//���f���̕`��
	/*	if (distance >= circleR) {
		DrawCircle(circleX, circleY, circleR , GetColor(255, 255, 0), true);
		DrawLine(lineX1, lineY1 - 200, lineX2, lineY2 - 200, GetColor(255, 255, 0), true);
		}
		else if (distance <= circleR) {
		DrawCircle(circleX, circleY, circleR, GetColor(255, 0, 0), true);
		DrawLine(lineX1, lineY1-200, lineX2, lineY2-200, GetColor(255, 0, 0), true);
		}*/

		/*if((10 + circleR) * (10 + circleR) <= (lineX1 - circleX) * (lineX1 - circleX) + (lineY1 - circleY) * (lineY1 - circleY) && (10 + circleR) * (10 + circleR) <= (lineX2 - circleX) * (lineX2 - circleX) + (lineY2 - circleY) * (lineY2 - circleY)) {
			DrawCircle(circleX, circleY, circleR, GetColor(255, 255, 0), true);
			DrawLine(lineX1, lineY1, lineX2, lineY2, GetColor(255, 255, 0), true);
		}*/



		DrawKeyOperation();	//�L�[����̕`��
		//�t���b�v����
		ScreenFlip();
	}

	DxLib::DxLib_End();

	//DxLib�I������
	return 0;
	//�\�t�g�̏I��
}
//xyz���̕`��
void DrawAxis3D(const float length)
{
	//���̐��̕`��
	//DrawLine3D(Vector3(-length, 0, 0), Vector3(+length, 0, 0), GetColor(255, 0, 0));	//x��
	//DrawLine3D(Vector3(0, -length, 0), Vector3(0, +length, 0), GetColor(0, 255, 0));	//y��
	//DrawLine3D(Vector3(0, 0, -length), Vector3(0, 0, +length), GetColor(0, 0, 255));	//z��

	////���̐�̕`�� xyz���̐���ۂɁA�~��������
	//const float coneSize = 10.0f;
	//DrawCone3D(Vector3(length, 0, 0), Vector3(length - coneSize, 0, 0), coneSize / 2, 16,
	//	GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
	//DrawCone3D(Vector3(0, length, 0), Vector3(0, length - coneSize, 0), coneSize / 2, 16,
	//	GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
	//DrawCone3D(Vector3(0, 0, length), Vector3(0, 0, length - coneSize), coneSize / 2, 16,
	//	GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
}
//�L�[����̕`��
void DrawKeyOperation()
{
	const unsigned white = GetColor(255, 255, 255);
	Draw(0, 0, interpolate0);
	Draw(0, 30, interpolate1);
	Draw(0, 60, interpolate2);
	Draw(0, 90, interpolate3);
	Draw(0, 120, interpolate4);

	DrawFormatString(350, 0, white, "interpolate0:Slerp(q0,q1,0.0f)");
	DrawFormatString(350, 30, white, "interpolate1:Slerp(q0,q1,0.3f)");
	DrawFormatString(350, 60, white, "interpolate2:Slerp(q0,q1,0.5f)");
	DrawFormatString(350, 90, white, "interpolate3:Slerp(q0,q1,0.7f)");
	DrawFormatString(350, 120, white, "interpolate4:Slerp(q0,q1,1.0f)");

}
	//�ȍ~�ADxLib�̊e�֐���Vector3�^Matrix4�^�𗘗p�ł���悤�ɂ���֐��Q//���̕`��//DxLib=>intDrawSphere3D(VECTORCenterPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
	int DrawSphere3D(const Vector3 & CenterPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag)
	{
		VECTOR centerPos = { CenterPos.x,CenterPos.y,CenterPos.z };	//�\���̏������q���X�g

		return DrawSphere3D(centerPos, r, DivNum, DifColor, SpcColor, FillFlag);
	}

	//DxLib=>intDrawCone3D(VECTORTopPos,VECTORBottomPos,floatr,intDivNum,unsignedintDifColor,unsignedintSpcColor,intFillFlag);
	int DrawCone3D(const Vector3 & TopPos, const Vector3 & BottomPos, const float r, const int DivNum, const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag)
	{
		VECTOR topPos = { TopPos.x,TopPos.y,TopPos.z };
		VECTOR bottomPos = { BottomPos.x,BottomPos.y,BottomPos.z };
		return DrawCone3D(topPos, bottomPos, r, DivNum, DifColor, SpcColor, FillFlag);
	}
	//�����̕`��//DxLib=>intDrawLine3D(VECTORPos1,VECTORPos2,unsignedintColor);
	int DrawLine3D(const Vector3 & Pos1, const Vector3 & Pos2, const unsigned int Color)
	{
		VECTOR p1 = { Pos1.x,Pos1.y,Pos1.z };//�\���̏������q���X�g
		VECTOR p2 = { Pos2.x,Pos2.y,Pos2.z };//�\���̏������q���X�g
		return DrawLine3D(p1, p2, Color);
	}
	//�J�����̈ʒu�Ǝp���̐ݒ�//DxLib=>intSetCameraPositionAndTargetAndUpVec(VECTORPosition,VECTORTarget,VECTORUp);
	int SetCameraPositionAndTargetAndUpVec(
		const Vector3 & cameraPosition,//�J�����̈ʒu
		const Vector3 & cameraTarget,//�J�����̒����_
		const Vector3 & cameraUp//�J�����̏�̌���
	)
	{
		VECTOR position = { cameraPosition.x,cameraPosition.y,cameraPosition.z };
		VECTOR target = { cameraTarget.x,cameraTarget.y,cameraTarget.z };
		VECTOR up = { cameraUp.x,cameraUp.y,cameraUp.z };
		return SetCameraPositionAndTargetAndUpVec(position, target, up);
	}
	//���f���̍��W�ϊ��p�s����Z�b�g����
	//DxLib=>intMV1SetMatrix(intMHandle,MATRIXMatrix);
	int MV1SetMatrix(const int MHandle, const Matrix4 Matrix)
	{
		MATRIX matrix; std::memcpy(&matrix, &Matrix, sizeof MATRIX);	//�������ԃR�s�[
		return MV1SetMatrix(MHandle, matrix);
	}

	void Draw(int x, int y, Quaternion q)
	{
		DrawFormatString(x, y, 0xffffff, "%f %f %f %f", q.v.x, q.v.y, q.v.z, q.w);
	}
