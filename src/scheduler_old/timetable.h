/*
 *  This file is a part of the PARUS project.
 *  Copyright (C) 2006  Alexander Sazonov (sazon666@mail.ru) and 
 *                      Alexey N. Salnikov (salnikov@cmc.msu.ru).
 *  
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 */

//timetable.hpp header file
//Used by timetable.cpp file by A. Sazonov's sch programm

#ifndef __TIMETABLE__H__
#define __TIMETABLE__H__

#include "creature.h"
#include "data.h"


	class Timetable
	{
        friend class Creature;
		friend class World;

	 protected:
		Timetable();
		Timetable(class Creature &object);
	 public:
		virtual ~Timetable();

	 public:
		bool Error(void) { return Err; }
//		bool Write(char* fname,int Age);
		void Out(void);
		int** Get(double & total);

		static int Get_N_Objects() { return N_Objects; }

	 protected:

		void Make(Creature& obj);
		double Get_Total(void) { return Total; }
		

	 private:
		int* 			nProcessor;
		int*			nNode;
		int				N_Nodes;
		double* 		Tau;
		double			Total;
		bool			Counted;
		bool 			Err;

		static Data*	Input;
		static int		N_Objects;
	};

#endif //__TIMETABLE__H__

