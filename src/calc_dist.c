#include "../inc/cub3d.h"

float   x_projection (float angle, float dist)
{
    float   projection;

    projection = -cos(angle) * dist;
    return (projection);
}

float   y_projection (float angle, float dist)
{
    float   projection;

    projection = sin(angle) * dist;
    return (projection);
}