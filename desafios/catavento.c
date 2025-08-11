#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

float angulo = 0.0f;
int sentido = 0;
char input[100];

void initCatavento(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // fundo branco
    glMatrixMode(GL_MODELVIEW); // Model view
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); // coordenadas 2D
}

void cataventoFunc(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    

	glColor3f(1.0, .0, .0);
	glBegin(GL_POLYGON);
		glVertex2i(248, 250);
		glVertex2i(251, 250);
		glVertex2i(248, 100);
		glVertex2i(251,100);
	glEnd();


    glPushMatrix(); // Indicamos que queremos rotacionar apenas a hélice de triângulo englobando num model view
    glTranslatef(250, 250, 0); // Para a origem
    glRotatef(angulo, 0, 0, 1); // Rotaciona ao redor da origem acima
    glTranslatef(-250, -250, 0); // Volta para a posição original (impede o que o objeto se desloque)

    int cx = 250, cy = 250; // centro do catavento



    // Pá 1 - cima
    glColor3f(1.0, 0.0, 0.0); // vermelho
    glBegin(GL_TRIANGLES);
        glVertex2i(cx, cy);
        glVertex2i(cx - 30, cy + 80);
        glVertex2i(cx + 30, cy + 80);
    glEnd();

    // Pá 2 - baixo
    glColor3f(0.0, 1.0, 0.0); // verde
    glBegin(GL_TRIANGLES);
        glVertex2i(cx, cy);
        glVertex2i(cx - 30, cy - 80);
        glVertex2i(cx + 30, cy - 80);
    glEnd();

    // Pá 3 - esquerda
    glColor3f(0.0, 0.0, 1.0); // azul
    glBegin(GL_TRIANGLES);
        glVertex2i(cx, cy);
        glVertex2i(cx - 80, cy - 30);
        glVertex2i(cx - 80, cy + 30);
    glEnd();

    // Pá 4 - direita
    glColor3f(1.0, 1.0, 0.0); // amarelo
    // glutPostRedisplay();
    glBegin(GL_TRIANGLES);
        glVertex2i(cx, cy);
        glVertex2i(cx + 80, cy - 30);
        glVertex2i(cx + 80, cy + 30);
    glEnd();



    glPopMatrix();
    glFlush();
}

void timer(int value) {
    if (sentido == 0){
        angulo += 10.0f;
    } else {
        angulo -= 10.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(70, timer, 0);
}
 
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r': // sentido horário
            sentido = 0;
            break;
        case 'l': // sentido anti-horário
            sentido = 1;
            break;
        default: // tecla ESC
            exit(0);
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Catavento");


    printf("Bem-Vindo ao Catavento!\n");
    printf("Tecla r: rotacione para o sentido anti-horário\n");
    printf("Tecla l: rotacione para o sentido horário\n");
    printf("Tecla ESC: sair\n");
    printf("Tecle ENTER para começar\n");
    while(strcmp(input, "\0") == 0){
        fgets(input, sizeof(input), stdin);
     
         
        if (strcmp(input, "\0") == 1) {
            break;
        }
    }

    initCatavento();
    glutDisplayFunc(cataventoFunc);
    glutTimerFunc(70, timer, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
