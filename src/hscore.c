/* yetris - Tetris(tm) on the console.
 * Copyright (C) 2013 Alexandre Dantas (kure)
 *
 * This file is part of yetris.
 *
 * yetris is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * homepage: http://www.github.com/alexdantas/yetris/
 * mailto:   alex.dantas92@gmail.com
 */

#include <string.h>
#include "hscore.h"

/*
1- how can i keep the high score between games?
if i call new_game(), it doesnt zero the hscore and
	it becomes trash. If i do, the hscore itself becomes
	zero.
	I cant seem to pass the previous high score to the next game
*/

/** Starts the high score list with default values  */
void hscore_init()
{
	/* Zeroes all high scores */
	int i;
	for (i = 0; i < MAX_HSCORES; i++)
		hscores[i] = new_score();

	/* My defaults :) */
	strncpy(hscores[0].name, "kure", 8);
	strncpy(hscores[0].date, "24/02/13", 8);
	strncpy(hscores[0].time, "20:13:55", 8);
	hscores[0].points = 1000;
	hscores[0].lines  = 100;
	hscores[0].level  = 10;
}

/** Creates an empty high score element */
score_s new_score()
{
	score_s s;

	memset(s.name, '\0', 11);
	memset(s.date, '\0', 9);
	memset(s.time, '\0', 9);
	s.points = 0;
	s.lines  = 0;
	s.level  = 0;

	return s;
}

/* int get_hscore_index(game_s* g, int score) */
/* { */
/* 	For (i = 10; i > 0; i--) */
/* 	{ */
/* 		if (score < g->scores[i]) */
/* 			return i; */
/* 	} */
/* 	return i; */
/* } */

/* ///////////////////////////////////////////////////////////////////////////
  score handling functions */

void hscore_handle(game_s* g)
{
	if (is_on_hscore_list(g->score))
		score_set(&(hscores[0]), "kure", g->score, g->lines, g->level);
	/* int i = get_hscore_index(g, g->score); */
}

bool is_on_hscore_list(int score)
{
	if (score >= hscore_get_lowest_points())
		return true;
	else
		return false;
}

/** Saves a score.
 *  It automagically handles date.
 */
void score_set(score_s* s, char name[], int points, int lines, int level)
{
	strncpy(s->name, name, 8);

	//MAKEdate!
	strncpy(s->date, "06/06/12", 8);
	strncpy(s->time, "11:99:22", 8);

	s->points = points;
	s->lines  = lines;
	s->level  = level;
}

/** Get the points from the first score on the list */
int hscore_get_highest_points()
{
	return hscores[0].points;
}

/** Get the points from the last score on the list */
int hscore_get_lowest_points()
{
	return hscores[MAX_HSCORES - 1].points;
}

