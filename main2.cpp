//////////Mise en place d'un RayTracing basique couplé à de l'antialising///////
//
////////////////////////////////////////////////////////////
/////////////////////Fichiers d'en tête/////////////////////
////////////////////////////////////////////////////////////
//
//
//#include <iostream>
//#include <fstream>
//#include <cmath>
//#include <vector>
//#include <random>
//#include <GL/glut.h>
//#include "C:\\Users\\maxen\\source\\repos\\RayTracing\\inc\\SOIL\\SOIL.h"
//
//using namespace std;
//
//
//struct Vecteur {
//    double x, y, z;
//    Vecteur(double x_ = 0, double y_ = 0, double z_ = 0) : x(x_), y(y_), z(z_) {}
//    Vecteur operator+(const Vecteur& aut) const { return Vecteur(x + aut.x, y + aut.y, z + aut.z); }
//    Vecteur operator-(const Vecteur& aut) const { return Vecteur(x - aut.x, y - aut.y, z - aut.z); }
//    Vecteur operator*(double scl) const { return Vecteur(x * scl, y * scl, z * scl); }
//    Vecteur operator/(double scl) const { return Vecteur(x / scl, y / scl, z / scl); }
//    double dot(const Vecteur& aut) const { return x * aut.x + y * aut.y + z * aut.z; }
//    Vecteur cross(const Vecteur& aut) const { return Vecteur(y * aut.z - z * aut.y, z * aut.x - x * aut.z, x * aut.y - y * aut.x); }
//    double longueur() const { return sqrt(x * x + y * y + z * z); }
//    Vecteur normale() const { return *this / longueur(); }
//};
//
//struct Ray {
//    Vecteur origine, direction;
//    Ray(const Vecteur& origine_, const Vecteur& direction_) : origine(origine_), direction(direction_) {}
//};
//
//struct Sphere {
//    Vecteur centre;
//    double rayon;
//    Sphere(const Vecteur& centre_, double rayon_) : centre(centre_), rayon(rayon_) {}
//
//    // Intersection Rayon - Sphère
//    bool intersect(const Ray& ray, double& t) const {
//        Vecteur oc = ray.origine - centre;
//        double a = ray.direction.dot(ray.direction);
//        double b = 2.0 * oc.dot(ray.direction);
//        double c = oc.dot(oc) - rayon * rayon;
//        double discriminant = b * b - 4 * a * c;
//        if (discriminant < 0) return false;
//        double sqrt_discriminant = sqrt(discriminant);
//        double r1 = (-b - sqrt_discriminant) / (2.0 * a);
//        double r2 = (-b + sqrt_discriminant) / (2.0 * a);
//        if (r1 > 0) {
//            t = r1;
//            return true;
//        }
//        else if (r2 > 0) {
//            t = r2;
//            return true;
//        }
//        return false;
//    }
//};
//
////////////////////////////////////////////////////////////
/////////////////////////Fichiers src///////////////////////
////////////////////////////////////////////////////////////
//
//Vecteur color(const Ray& ray) {
//    Sphere sphere(Vecteur(0, 0, -1), 0.5);
//    double t;
//    if (sphere.intersect(ray, t)) {
//        Vecteur normal = (ray.origine + ray.direction * t - sphere.centre).normale();
//        return Vecteur(0.5 * (normal.x + 1), 0.5 * (normal.y + 1), 0.5 * (normal.z + 1));
//    }
//    Vecteur unit_direction = ray.direction.normale();
//    t = 0.5 * (unit_direction.y + 1.0);
//    return Vecteur((1.0 - t) * 1.0, (1.0 - t) * 1.0, (1.0 - t) * 1.0) + Vecteur(t * 0.5, t * 0.7, t * 1.0);
//}
//
//void renderScene() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glViewport(0, 0, 800, 600);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, 800.0 / 600.0, 1.0, 500.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//    glEnable(GLUT_MULTISAMPLE);
//    glBegin(GL_QUADS);
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex2f(-0.5, -0.5);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2f(0.5, -0.5);
//    glColor3f(0.0, 0.0, 1.0);
//    glVertex2f(0.5, 0.5);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2f(-0.5, 0.5);
//    glEnd();
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE); 
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Ray Tracing opéré avec de l'antialiasing sur un objet 2D");
//    glutDisplayFunc(renderScene);
//    glutMainLoop();
//    return 0;
//}