#include "CTransform.h"
#include "math.h"
#include <iostream>
#include <stdio.h>
#define PI 3.14159265


/*************************************************************************/

CTransform::CTransform(){

    int value = 4;
        mat = new GLfloat[value][4];
	
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = 0;
	
	mat[1][0] = 0;
	mat[1][1] = 1;
	mat[1][2] = 0;
	mat[1][3] = 0;
	
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;
	mat[2][3] = 0;

	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;

}

/*************************************************************************/

void CTransform::print(void){

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*************************************************************************/

void CTransform::rotate(Axis a, GLfloat degrees){

	float (*rot_mat)[4];
	
	int num = 4;
        rot_mat = new GLfloat[num][4];
	
	// Initialisierung von Transformation mit Einheitsmatrix
	rot_mat[0][0] = 1;
	rot_mat[0][1] = 0;
	rot_mat[0][2] = 0;
	rot_mat[0][3] = 0;
	
	rot_mat[1][0] = 0;
	rot_mat[1][1] = 1;
	rot_mat[1][2] = 0;
	rot_mat[1][3] = 0;
	
	rot_mat[2][0] = 0;
	rot_mat[2][1] = 0;
	rot_mat[2][2] = 1;
	rot_mat[2][3] = 0;

	rot_mat[3][0] = 0;
	rot_mat[3][1] = 0;
	rot_mat[3][2] = 0;
	rot_mat[3][3] = 1;

	switch(a){
	
        case 0:	rot_mat[1][1] = cos(degrees*PI/180);
                        rot_mat[1][2] = -sin(degrees*PI/180);
                        rot_mat[2][1] = sin(degrees*PI/180);
                        rot_mat[2][2] = cos(degrees*PI/180);
                        break;

        case 1: rot_mat[0][0] = cos(degrees*PI/180);
                        rot_mat[0][2] = sin(degrees*PI/180);
                        rot_mat[2][0] = -sin(degrees*PI/180);
                        rot_mat[2][2] = cos(degrees*PI/180);
                        break;

        case 2:	rot_mat[0][0] = cos(degrees*PI/180);
                        rot_mat[0][1] = -sin(degrees*PI/180);
                        rot_mat[1][0] = sin(degrees*PI/180);
                        rot_mat[1][1] = cos(degrees*PI/180);
                        break;

				
	}
		

	multMatrix(rot_mat,mat);
}

/*************************************************************************/

void CTransform::scale(Axis a, GLfloat factor){

        GLfloat (*sca_mat)[4];

	int num = 4;
        sca_mat = new GLfloat[num][4];
	
	
	
	// Initialisierung von Scalierung mit Einheitsmatrix
	sca_mat[0][0] = 1;
	sca_mat[0][1] = 0;
	sca_mat[0][2] = 0;
	sca_mat[0][3] = 0;
	
	sca_mat[1][0] = 0;
	sca_mat[1][1] = 1;
	sca_mat[1][2] = 0;
	sca_mat[1][3] = 0;
	
	sca_mat[2][0] = 0;
	sca_mat[2][1] = 0;
	sca_mat[2][2] = 1;
	sca_mat[2][3] = 0;

	sca_mat[3][0] = 0;
	sca_mat[3][1] = 0;
	sca_mat[3][2] = 0;
	sca_mat[3][3] = 1;

	switch(a)
	{
	
		case 0: sca_mat[0][0] = factor;
				break;
		case 1: sca_mat[1][1] = factor;
				break;
		case 2: sca_mat[2][2] = factor;
				break;
	}
	
	multMatrix(sca_mat,mat);
	
}

/*************************************************************************/

void CTransform::translate(Axis a, GLfloat distance){

        GLfloat (*trans_mat)[4];

	int num = 4;
        trans_mat = new GLfloat[num][4];
	
	// Initialisierung von Scalierung mit Einheitsmatrix
	trans_mat[0][0] = 1;
	trans_mat[0][1] = 0;
	trans_mat[0][2] = 0;
	trans_mat[0][3] = 0;
	
	trans_mat[1][0] = 0;
	trans_mat[1][1] = 1;
	trans_mat[1][2] = 0;
	trans_mat[1][3] = 0;
	
	trans_mat[2][0] = 0;
	trans_mat[2][1] = 0;
	trans_mat[2][2] = 1;
	trans_mat[2][3] = 0;

	trans_mat[3][0] = 0;
	trans_mat[3][1] = 0;
	trans_mat[3][2] = 0;
	trans_mat[3][3] = 1;

	switch(a)
	{
	
		case 0: trans_mat[0][3] = distance;
                    std::cout << "TRANSLATE --------> X" << distance << std::endl;
				break;
		case 1: trans_mat[1][3] = distance;
                    std::cout << "TRANSLATE --------> Y" << distance << std::endl;
				break;
		case 2: trans_mat[2][3] = distance;
                    std::cout << "TRANSLATE --------> Z" << distance << std::endl;
				break;
	}
	
	multMatrix(trans_mat,mat);

}

/*************************************************************************/

void CTransform::transform(GLfloat *x, GLfloat *y, GLfloat *z){
	
	
	int i,j;
	

        GLfloat *n_vector = new GLfloat[4];
        GLfloat *current_vector = new GLfloat[4];

        n_vector[0] = 0;
        n_vector[1] = 0;
        n_vector[2] = 0;
	n_vector[3] = 0;

        current_vector[0] =  *x;
        current_vector[1] =  *y;
        current_vector[2] =  *z;
        current_vector[3] =  1;


        for(i=0;i<4;i++)
        {
                for(j=0;j<4;j++)
                {
                        n_vector[i] += mat[i][j] *current_vector[j];
                }


        }

        *x = n_vector[0];
        *y = n_vector[1];
        *z = n_vector[2];



}

/*************************************************************************/

void CTransform::multMatrix(GLfloat matrix_1[4][4], GLfloat matrix_2[4][4]){

	int i,j,k;
	
        GLfloat (*tmp_matrix)[4];
	
	int num = 4;
        tmp_matrix = new GLfloat[num][4];

	
	//initialisierung der TEMP_Matrix mit 0
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			tmp_matrix[i][j]=0;
		}
	}
	
	
	
	// multiplikation der beiden Matrizen 1 und 2
	for(i=0; i < 4; i++)
	{
		for(j=0; j < 4; j++)
		{
			for(k=0; k < 4 ; k++)
			{
				tmp_matrix[i][j] += matrix_1[i][k]*matrix_2[k][j];
			}
		}
	}
	
	
	// kopiere TEMP_MATRIX in MAT
	for(i=0;i < 4;i++)
	{
		for(j=0;j<4;j++)
		{
			mat[i][j] = tmp_matrix[i][j];
		}
	}


}





