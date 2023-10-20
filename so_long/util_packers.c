#include "so_long.h"

t_coords pack_coorniates(t_xy dims, t_xy *curr, t_xy *child, t_xy e_xy)
{
    t_coords    coords;

    coords.dims = dims;
    coords.child_cell = child;
    coords.curr_cell = curr;
    coords.e_xy = e_xy;
    return (coords);
}