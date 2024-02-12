//////////////Mise en place d'un RayTracing basique///////////
//
//
//////////////////////////////////////////////////////////////
///////////////////////Fichiers d'en tête/////////////////////
//////////////////////////////////////////////////////////////
//
//#include <iostream>
//#include <fstream>
//#include <cmath>
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
//    double point(const Vecteur& aut) const { return x * aut.x + y * aut.y + z * aut.z; }
//    Vecteur cr(const Vecteur& aut) const { return Vecteur(y * aut.z - z * aut.y, z * aut.x - x * aut.z, x * aut.y - y * aut.x); }
//    double longueur() const { return sqrt(x * x + y * y + z * z); }
//    Vecteur normale() const { return *this / longueur(); }
//};
//
//Vecteur operator*(double scl, const Vecteur& v) { return Vecteur(v.x * scl, v.y * scl, v.z * scl); }
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
//    bool intersect(const Ray& ray, double& t) const {
//        Vecteur oc = ray.origine - centre;
//        double a = ray.direction.point(ray.direction);
//        double b = 2.0 * oc.point(ray.direction);
//        double c = oc.point(oc) - rayon * rayon;
//        double discriminant = b * b - 4 * a * c;
//        if (discriminant < 0) return false;
//        double sqrt_discriminant = sqrt(discriminant);
//        double r1 = (-b - sqrt_discriminant) / (2.0 * static_cast<double>(a));
//        double r2 = (-b + sqrt_discriminant) / (2.0 * static_cast<double>(a));
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
//
//////////////////////////////////////////////////////////////
///////////////////////////Fichiers src///////////////////////
//////////////////////////////////////////////////////////////
//
//Vecteur color(const Ray& ray) {
//    Sphere sphere(Vecteur(0, 0, -1), 0.5);
//    double t;
//    if (sphere.intersect(ray, t)) {
//        Vecteur origine_vers_intersection = ray.origine + t * ray.direction;
//        Vecteur normal = (origine_vers_intersection - sphere.centre).normale();
//        return 0.5 * Vecteur(normal.x + 1, normal.y + 1, normal.z + 1);
//    }
//    Vecteur unit_direction = ray.direction.normale();
//    t = 0.5 * (unit_direction.y + 1.0);
//    return (1.0 - t) * Vecteur(1.0, 1.0, 1.0) + t * Vecteur(0.5, 0.7, 1.0);
//}
//
//int main() {
//    int image_width = 200;
//    int image_height = 100;
//
//    ofstream image("raytracing.ppm");
//    image << "P3\n" << image_width << " " << image_height << "\n255\n";
//
//    Vecteur lower_left_corner(-2.0, -1.0, -1.0);
//    Vecteur horizontal(4.0, 0.0, 0.0);
//    Vecteur vertical(0.0, 2.0, 0.0);
//    Vecteur origine(0.0, 0.0, 0.0);
//
//    for (int j = image_height - 1; j >= 0; --j) {
//        for (int i = 0; i < image_width; ++i) {
//            double u = static_cast<double>(i) / (image_width - 1);
//            double v = static_cast<double>(j) / (image_height - 1);
//            Ray ray(origine, lower_left_corner + u * horizontal + v * vertical);
//            Vecteur col = color(ray);
//            int ir = int(255.999 * col.x);
//            int ig = int(255.999 * col.y);
//            int ib = int(255.999 * col.z);
//            image << ir << " " << ig << " " << ib << "\n";
//        }
//    }
//
//    image.close();
//    return 0;
//}
//
//