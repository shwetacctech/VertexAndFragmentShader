# Point3D Class for 3D Coordinates

The `Point3D` class in C++ represents a point in three-dimensional space by defining its x, y, and z coordinates. It provides methods to access and modify these coordinates.

## Class: Point3D

### Constructors

#### `Point3D()`
- Initializes a 3D point with default coordinates (0.0, 0.0, 0.0).

#### `Point3D(double x_coord, double y_coord, double z_coord)`
- Initializes a 3D point with specific coordinates: `x_coord`, `y_coord`, and `z_coord`.

### Methods

#### Getter Methods

##### `double getX() const`
- Retrieves the x-coordinate of the point.

##### `double getY() const`
- Retrieves the y-coordinate of the point.

##### `double getZ() const`
- Retrieves the z-coordinate of the point.

#### Setter Methods

##### `void setX(double x_coord)`
- Sets the x-coordinate of the point to the provided value `x_coord`.

##### `void setY(double y_coord)`
- Sets the y-coordinate of the point to the provided value `y_coord`.

##### `void setZ(double z_coord)`
- Sets the z-coordinate of the point to the provided value `z_coord`.

### Usage

You can use the `Point3D` class to represent points in a three-dimensional space. Create instances of this class and utilize its methods to access or modify the coordinates of points.

### Example

```cpp
// Example usage of the Point3D class
#include "Point3D.h"
#include <iostream>

int main() {
    Point3D point1; // Creates a point at the origin
    std::cout << "Point 1 coordinates: (" << point1.getX() << ", " << point1.getY() << ", " << point1.getZ() << ")" << std::endl;

    Point3D point2(2.0, 3.0, 4.0); // Creates a point with specific coordinates
    std::cout << "Point 2 coordinates: (" << point2.getX() << ", " << point2.getY() << ", " << point2.getZ() << ")" << std::endl;

    // Modify coordinates
    point1.setX(5.0);
    point1.setY(6.0);
    point1.setZ(7.0);
    std::cout << "New coordinates of Point 1: (" << point1.getX() << ", " << point1.getY() << ", " << point1.getZ() << ")" << std::endl;

    return 0;
}
