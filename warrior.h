#include "class.h"

Warrior :: Warrior(Magic *magic, Weapons *weapons)
{
    srand(time(0)); //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> physicalStrenght = attributes [1];
    this -> magicalStrenght = attributes [2];
    this -> armor = attributes [3];
    this -> magicalResistance = attributes [4];
    this -> agility = attributes [5];
    this -> maxMana = attributes [6];

    this -> magic = magic;
    this -> weapons = weapons;

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 2;
    weaponIndex[1] = 6;

}

int Warrior :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2) //O personagem esquiva se a porcentagen for menor que a agilidade 
    return 1;

    else 
    return 0;
}

int Warrior :: receiveDamage(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Warrior :: physicalDamageCalculator () //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    cout<<"\n"<< damage << "\n";

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    return damage;
}

int Warrior :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
return escolha;    
}

void Warrior :: changeWeapon() //Função para a troca de armas
{

}

void Warrior :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


void Warrior :: imprime()
{

cout<<"\n"<<this->hp<<"\n";


}


Warrior :: ~Warrior() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};