#ifndef _CTRANSFORM_H
#define _CTRANSFORM_H
#include "CTransform.h"
#include "QGLWidget"

enum Axis{X,Y,Z};

class CTransform{

	public:
		

		CTransform();
                void rotate(Axis a, GLfloat degrees);
                void scale(Axis a, GLfloat factor);
                void translate(Axis a, GLfloat distance);
		void print(void);
		
                void transform(GLfloat *x, GLfloat *y, GLfloat *z);
		

	
	private:

                GLfloat (*mat)[4];
                void multMatrix(GLfloat matrix_1[4][4], GLfloat matrix_2[4][4]);

};

#endif /* _CTRANSFORM_H */


 
