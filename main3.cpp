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
//struct Vecteur {
//    double x, y, z;
//    Vecteur(double x_ = 0, double y_ = 0, double z_ = 0) : x(x_), y(y_), z(z_) {}
//    Vecteur operator+(const Vecteur& aut) const { return Vecteur(x + aut.x, y + aut.y, z + aut.z); }
//    Vecteur operator-(const Vecteur& aut) const { return Vecteur(x - aut.x, y - aut.y, z - aut.z); }
//    Vecteur operator*(double scl) const { return Vecteur(x * scl, y * scl, z * scl); }
//    Vecteur operator/(double scl) const { return Vecteur(x / scl, y / scl, z / scl); }
//    double point(const Vecteur& aut) const { return x * aut.x + y * aut.y + z * aut.z; }
//    Vecteur cr(const Vecteur& aut) const { return Vecteur(y * aut.z - z * aut.y, z * aut.x - x * aut.z, x * aut.y - y * aut.x); }
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
//    bool intersect(const Ray& ray, double& t) const {
//        Vecteur oc = ray.origine - centre;
//        double a = ray.direction.point(ray.direction);
//        double b = 2.0 * oc.point(ray.direction);
//        double c = oc.point(oc) - rayon * rayon;
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
//Vecteur color(const Ray& ray, const std::vector<Sphere>& spheres, int depth = 0) {
//    double t_min = INFINITY;
//    const Sphere* hit_sphere = nullptr;
//
//    for (const Sphere& sphere : spheres) {
//        double t;
//        if (sphere.intersect(ray, t) && t < t_min) {
//            t_min = t;
//            hit_sphere = &sphere;
//        }
//    }
//
//    if (!hit_sphere) {
//        Vecteur unit_direction = ray.direction.normale();
//        double t = 0.5 * (unit_direction.y + 1.0);
//        return Vecteur((1.0 - t) * 1.0, (1.0 - t) * 1.0, (1.0 - t) * 1.0) + Vecteur(t * 0.5, t * 0.7, t * 1.0);
//    }
//
//    if (depth >= 50) {
//        return Vecteur(0, 0, 0);
//    }
//
//    Vecteur hit_point = ray.origine + ray.direction * t_min;
//    Vecteur normal = (hit_point - hit_sphere->centre).normale();
//    Vecteur reflected_direction = ray.direction - normal * 2 * ray.direction.point(normal);
//    Ray reflected_ray(hit_point, reflected_direction);
//
//    return color(reflected_ray, spheres, depth + 1) * 0.5;
//}
//
//GLuint loadTexture(const char* filename) {
//    GLuint texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
//    if (texture == 0) {
//        cerr << "La texture n'a pas pu charger correctement ! " << SOIL_last_result() << endl;
//    }
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    return texture;
//}
//
////void renderScene() {
////    glClear(GL_COLOR_BUFFER_BIT);
////    glViewport(0, 0, 800, 600);
////    glMatrixMode(GL_PROJECTION);
////    glLoadIdentity();
////    gluPerspective(45.0, 800.0 / 600.0, 1.0, 500.0);
////    glMatrixMode(GL_MODELVIEW);
////    glLoadIdentity();
////    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
////
////    std::vector<Sphere> spheres;
////    spheres.push_back(Sphere(Vecteur(0, 0, -1), 0.5));
////
////    int largeur = 800, hauteur = 600;
////    std::vector<Vecteur> image(largeur * hauteur);
////
////    for (int j = 0; j < hauteur; ++j) {
////        for (int i = 0; i < largeur; ++i) {
////            double u = double(i) / double(largeur);
////            double v = double(j) / double(hauteur);
////            Ray ray(Vecteur(0, 0, 0), Vecteur(u - 0.5, v - 0.5, -1).normale());
////            image[j * largeur + i] = color(ray, spheres);
////        }
////    }
////
////    glDrawPixels(largeur, hauteur, GL_RGB, GL_FLOAT, image.data());
////
////    glutSwapBuffers();
////}
////
////int main(int argc, char** argv) {
////    glutInit(&argc, argv);
////    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
////    glutInitWindowSize(800, 600);
////    glutCreateWindow("Ray Tracing with OpenGL Antialiasing");
////    glutDisplayFunc(renderScene);
////    glutMainLoop();
////
////    return 0;
////}
//
//void renderScene() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glViewport(0, 0, 800, 600);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, 800.0 / 600.0, 1.0, 500.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0); 
//
//    std::vector<Sphere> spheres;
//    spheres.push_back(Sphere(Vecteur(0, 0, -1), 0.5));
//
//    int largeur = 800, hauteur = 600;
//    std::vector<Vecteur> image(largeur * hauteur);
//
//    for (int j = 0; j < hauteur; ++j) {
//        for (int i = 0; i < largeur; ++i) {
//            double u = 2.0 * ((i + 0.5) / double(largeur) - 0.5);
//            double v = 2.0 * ((j + 0.5) / double(hauteur) - 0.5);
//            Ray ray(Vecteur(0, 0, 0), Vecteur(u, v, -1).normale());
//            image[j * largeur + i] = color(ray, spheres);
//        }
//    }
//
//    glDrawPixels(largeur, hauteur, GL_RGB, GL_FLOAT, image.data());
//
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Essai n°3 de Ray Tracing avec Antialising et Texture Mapping");
//    glutDisplayFunc(renderScene);
//    glutMainLoop();
//
//    return 0;
//}