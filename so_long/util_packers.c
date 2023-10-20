#include "so_long.h"

t_coords pack_coorniates(t_coordinate dims, t_coordinate *curr, t_coordinate *child, t_coordinate Es)
{
    t_coords    coords;

    coords.dims = dims;
    coords.child_cell = child;
    coords.curr_cell = curr;
    coords.Es = Es;
    return (coords);
}