#include "so_long.h"

void	set_row_cols(t_xy *curr, t_xy *child, t_xys *coords)
{
	curr->row = coords->curr_cell->row;
	curr->col = coords->curr_cell->col;
	child->row = coords->child_cell->row;
	child->col = coords->child_cell->col;
}

void	set_content(t_key_value *content, t_xy child, t_xy curr)
{
	content->key.row = child.row;
	content->key.col = child.col;
	content->value.row = curr.row;
	content->value.col = curr.col;
}
