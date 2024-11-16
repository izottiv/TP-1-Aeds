#ifndef TAD_CATEGORIAS_H
#define TAD_CATEGORIAS_H

//Enum das possiveis Categorias
typedef enum  {
    Ferrom,
    Solaris,
    Aquaferro,
    Terrolis,
    Terrasol,
    Aquaterra,
    Calquer,
    Solarisfer,
    Terralis,
    Aquacalis,
} Categorias;

void ClassificaCategoria(RochaMineral* Rocha);     //Classifica as CATEGORIAS de uma rocha

#endif