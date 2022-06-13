#ifndef AFFECTATION_H
#define AFFECTATION_H


class Affectation
{
public:
    Affectation(int ide, int ids);
    int getIdE(){ return this->id_emp;};
    int getIdS(){ return this->id_ser;};

    bool creer();

private:
    int id_emp;
    int id_ser;
};

#endif // AFFECTATION_H
