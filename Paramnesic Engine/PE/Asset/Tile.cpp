#include "Tile.hpp"

unsigned int pe::Tile::COUNT = 1;

pe::Tile::Tile() : pe::Asset("Tile ", pe::Tile::COUNT++)
{

}

pe::Tile::~Tile()
{

}