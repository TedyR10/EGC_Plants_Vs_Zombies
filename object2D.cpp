#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}


Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices
    {
        VertexFormat(glm::vec3(-0.30909, 0.43915, 1), color),
        VertexFormat(glm::vec3(-1.30682, 0.34629, 1), color),
        VertexFormat(glm::vec3(-0.50682, -0.15371, 1), color),

        VertexFormat(glm::vec3(0.50682, -0.15371, 1), color),
        VertexFormat(glm::vec3(-0.50682, -0.15371, 1), color),
        VertexFormat(glm::vec3(-0.70682, -1.15371, 1), color),

        VertexFormat(glm::vec3(0.50682, -0.15371, 1), color),
        VertexFormat(glm::vec3(-0.50682, -0.15371, 1), color),
        VertexFormat(glm::vec3(0.70682, -1.15371, 1), color),

        VertexFormat(glm::vec3(0.30909, 0.43915, 1), color),
        VertexFormat(glm::vec3(0.50682, -0.15371, 1), color),
        VertexFormat(glm::vec3(1.30682, 0.34629, 1), color),

        VertexFormat(glm::vec3(-0.00909, 1.35915, 1), color),
        VertexFormat(glm::vec3(-0.50682, -0.15371, 1), color),
        VertexFormat(glm::vec3(0.50682, -0.15371, 1), color),


    };
    std::vector<unsigned int> indices =
    {
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11,
        12, 13, 14,
    };

    Mesh* star = new Mesh(name);

    star->InitFromData(vertices, indices);
    return star;
}

Mesh* object2D::CreateDiamond(
    const std::string& name,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices
    {
        VertexFormat(glm::vec3(-0.23967, 0.99285, 1), color),
        VertexFormat(glm::vec3(-0.73967, -0.00715, 1), color),
        VertexFormat(glm::vec3(0.26033, -0.00715, 1), color),

        VertexFormat(glm::vec3(-0.73967, -0.00715, 1), color),
        VertexFormat(glm::vec3(-0.23967, -0.99285, 1), color),
        VertexFormat(glm::vec3(0.26033, -0.00715, 1), color),

        VertexFormat(glm::vec3(0.14033, 0.22285, 1), color),
        VertexFormat(glm::vec3(0.14033, -0.22285, 1), color),
        VertexFormat(glm::vec3(0.99569, 0.22285, 1), color),

        VertexFormat(glm::vec3(0.99569, 0.22285, 1), color),
        VertexFormat(glm::vec3(0.14033, -0.22285, 1), color),
        VertexFormat(glm::vec3(0.99569, -0.22285, 1), color),


    };
    std::vector<unsigned int> indices =
    {
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11,
    };

    Mesh* diamond = new Mesh(name);

    diamond->InitFromData(vertices, indices);
    return diamond;
}

Mesh* object2D::CreateHex(
    const std::string& name,
    glm::vec3 color1,
    glm::vec3 color2,
    bool fill)
{

    std::vector<VertexFormat> vertices
    {

        // Outer hex
        VertexFormat(glm::vec3(-0.866025, 0.5, 1), color1),
        VertexFormat(glm::vec3(-0.866025, -0.5, 1), color1),
        VertexFormat(glm::vec3(0, 0, 1), color1),

        VertexFormat(glm::vec3(-0.866025, -0.5, 1), color1),
        VertexFormat(glm::vec3(0, -1, 1), color1),
        VertexFormat(glm::vec3(0, 0, 1), color1),

        VertexFormat(glm::vec3(0, -1, 1), color1),
        VertexFormat(glm::vec3(0.866025, -0.5, 1), color1),
        VertexFormat(glm::vec3(0, 0, 1), color1),

        VertexFormat(glm::vec3(0.866025, -0.5, 1), color1),
        VertexFormat(glm::vec3(0.866025, 0.5, 1), color1),
        VertexFormat(glm::vec3(0, 0, 1), color1),

        VertexFormat(glm::vec3(0.866025, 0.5, 1), color1),
        VertexFormat(glm::vec3(0, 1, 1), color1),
        VertexFormat(glm::vec3(0, 0, 1), color1),

        VertexFormat(glm::vec3(0, 1, 1), color1),
        VertexFormat(glm::vec3(-0.866025, 0.5, 1), color1),
        VertexFormat(glm::vec3(0, 0, 1), color1),

        // Inner hex
        VertexFormat(glm::vec3(-0.4330125, 0.25, 2), color2),
        VertexFormat(glm::vec3(-0.4330125, -0.25, 2), color2),
        VertexFormat(glm::vec3(0, 0, 2), color2),

        VertexFormat(glm::vec3(-0.4330125, -0.25, 2), color2),
        VertexFormat(glm::vec3(0, -0.5, 2), color2),
        VertexFormat(glm::vec3(0, 0, 2), color2),

        VertexFormat(glm::vec3(0, -0.5, 2), color2),
        VertexFormat(glm::vec3(0.4330125, -0.25, 2), color2),
        VertexFormat(glm::vec3(0, 0, 2), color2),

        VertexFormat(glm::vec3(0.4330125, -0.25, 2), color2),
        VertexFormat(glm::vec3(0.4330125, 0.25, 2), color2),
        VertexFormat(glm::vec3(0, 0, 2), color2),

        VertexFormat(glm::vec3(0.4330125, 0.25, 2), color2),
        VertexFormat(glm::vec3(0, 0.5, 2), color2),
        VertexFormat(glm::vec3(0, 0, 2), color2),

        VertexFormat(glm::vec3(0, 0.5, 2), color2),
        VertexFormat(glm::vec3(-0.4330125, 0.25, 2), color2),
        VertexFormat(glm::vec3(0, 0, 2), color2),

    };
    std::vector<unsigned int> indices =
    {
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11,
        12, 13, 14,
        15, 16, 17,

        18, 19, 20,
        21, 22, 23,
        24, 25, 26,
        27, 28, 29,
        30, 31, 32,
        33, 34, 35,

    };

    Mesh* hex = new Mesh(name);

    hex->InitFromData(vertices, indices);
    return hex;
}
