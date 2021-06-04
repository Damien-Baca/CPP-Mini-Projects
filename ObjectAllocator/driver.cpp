/****************************************************************************/
/*!
\author Damien P Baca
\par    email: damien.baca@digipen.edu
\par    DigiPen login: damien.baca
\par    course: cs280
*/
/****************************************************************************/
#include <iostream>
#include "ObjectAllocator.h"

struct Student
{
  int Age;
  float GPA;
  unsigned long Year;
  unsigned long ID;
};

int main(void)
{
	ObjectAllocator *oa;

    bool newdel = false;
    bool debug = false;
    unsigned padbytes = 0;
    OAConfig::HeaderBlockInfo header(OAConfig::hbNone);
    unsigned alignment = 0;

    const unsigned objects = 20;
    const unsigned pages = 5;

	OAConfig config(newdel, objects, pages, debug, padbytes, header, alignment);
    oa  = new ObjectAllocator(sizeof(Student), config);

    Student *Damien = reinterpret_cast<Student*>(oa->Allocate());
    Damien->Age = 18;
    Damien->GPA = 4.0;
    Damien->Year = 1996;
    Damien->ID = 180005314;



    std::cout << "Age" << Damien->Age << "\n"
              << "GPA" << Damien->GPA << "\n"
              << "Year" << Damien->Year<< "\n"
              << "ID" << Damien->ID  << "\n"
              << std::endl;

    oa->Free(Damien);
}
