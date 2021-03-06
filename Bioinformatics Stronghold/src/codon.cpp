#include <iostream>
#include <string>
#include <map>
#include "../include/codon.h"

Codon::Codon() {

}

MapSS Codon::rnaCodonMap{ 
	{"UUU", "F"}, {"UUC", "F"}, {"UUA", "L"}, 
	{"UUG", "L"}, {"UCU", "S"}, {"UCC", "S"},
	{"UCA", "S"}, {"UCG", "S"}, {"UAU", "Y"},
	{"UAC", "Y"}, {"UAA", "Stop"}, {"UAG", "Stop"},
	{"UGU", "C"}, {"UGC", "C"}, {"UGA", "Stop"},
	{"UGG", "W"}, {"CUU", "L"}, {"CUC", "L"},
	{"CUA", "L"}, {"CUG", "L"}, {"CCU", "P"},
	{"CCC", "P"}, {"CCA", "P"}, {"CCG", "P"},
	{"CAU", "H"}, {"CAC", "H"}, {"CAA", "Q"},
	{"CAG", "Q"}, {"CGU", "R"}, {"CGC", "R"},
	{"CGA", "R"}, {"CGG", "R"}, {"AUU", "I"},
	{"AUC", "I"}, {"AUA", "I"}, {"AUG", "M"},
	{"ACU", "T"}, {"ACC", "T"}, {"ACA", "T"},
	{"ACG", "T"}, {"AAU", "N"}, {"AAC", "N"},
	{"AAA", "K"}, {"AAG", "K"}, {"AGU", "S"},
	{"AGC", "S"}, {"AGA", "R"}, {"AGG", "R"},
	{"GUU", "V"}, {"GUC", "V"}, {"GUA", "V"},
	{"GUG", "V"}, {"GCU", "A"}, {"GCC", "A"},
	{"GCA", "A"}, {"GCG", "A"}, {"GAU", "D"},
	{"GAC", "D"}, {"GAA", "E"}, {"GAG", "E"},
	{"GGU", "G"}, {"GGC", "G"}, {"GGA", "G"},
	{"GGG", "G"}
	};

MapSS Codon::dnaCodonMap{ 
	{"TTT", "F"}, {"TTC", "F"}, {"TTA", "L"}, 
	{"TTG", "L"}, {"TCT", "S"}, {"TCC", "S"},
	{"TCA", "S"}, {"TCG", "S"}, {"TAT", "Y"},
	{"TAC", "Y"}, {"TAA", "Stop"}, {"TAG", "Stop"},
	{"TGT", "C"}, {"TGC", "C"}, {"TGA", "Stop"},
	{"TGG", "W"}, {"CTT", "L"}, {"CTC", "L"},
	{"CTA", "L"}, {"CTG", "L"}, {"CCT", "P"},
	{"CCC", "P"}, {"CCA", "P"}, {"CCG", "P"},
	{"CAT", "H"}, {"CAC", "H"}, {"CAA", "Q"},
	{"CAG", "Q"}, {"CGT", "R"}, {"CGC", "R"},
	{"CGA", "R"}, {"CGG", "R"}, {"ATT", "I"},
	{"ATC", "I"}, {"ATA", "I"}, {"ATG", "M"},
	{"ACT", "T"}, {"ACC", "T"}, {"ACA", "T"},
	{"ACG", "T"}, {"AAT", "N"}, {"AAC", "N"},
	{"AAA", "K"}, {"AAG", "K"}, {"AGT", "S"},
	{"AGC", "S"}, {"AGA", "R"}, {"AGG", "R"},
	{"GTT", "V"}, {"GTC", "V"}, {"GTA", "V"},
	{"GTG", "V"}, {"GCT", "A"}, {"GCC", "A"},
	{"GCA", "A"}, {"GCG", "A"}, {"GAT", "D"},
	{"GAC", "D"}, {"GAA", "E"}, {"GAG", "E"},
	{"GGT", "G"}, {"GGC", "G"}, {"GGA", "G"},
	{"GGG", "G"}
	};

MapSS Codon::getRnaCodonMap() {
	MapSS rnaCodon{ 
	{"UUU", "F"}, {"UUC", "F"}, {"UUA", "L"}, 
	{"UUG", "L"}, {"UCU", "S"}, {"UCC", "S"},
	{"UCA", "S"}, {"UCG", "S"}, {"UAU", "Y"},
	{"UAC", "Y"}, {"UAA", "Stop"}, {"UAG", "Stop"},
	{"UGU", "C"}, {"UGC", "C"}, {"UGA", "Stop"},
	{"UGG", "W"}, {"CUU", "L"}, {"CUC", "L"},
	{"CUA", "L"}, {"CUG", "L"}, {"CCU", "P"},
	{"CCC", "P"}, {"CCA", "P"}, {"CCG", "P"},
	{"CAU", "H"}, {"CAC", "H"}, {"CAA", "Q"},
	{"CAG", "Q"}, {"CGU", "R"}, {"CGC", "R"},
	{"CGA", "R"}, {"CGG", "R"}, {"AUU", "I"},
	{"AUC", "I"}, {"AUA", "I"}, {"AUG", "M"},
	{"ACU", "T"}, {"ACC", "T"}, {"ACA", "T"},
	{"ACG", "T"}, {"AAU", "N"}, {"AAC", "N"},
	{"AAA", "K"}, {"AAG", "K"}, {"AGU", "S"},
	{"AGC", "S"}, {"AGA", "R"}, {"AGG", "R"},
	{"GUU", "V"}, {"GUC", "V"}, {"GUA", "V"},
	{"GUG", "V"}, {"GCU", "A"}, {"GCC", "A"},
	{"GCA", "A"}, {"GCG", "A"}, {"GAU", "D"},
	{"GAC", "D"}, {"GAA", "E"}, {"GAG", "E"},
	{"GGU", "G"}, {"GGC", "G"}, {"GGA", "G"},
	{"GGG", "G"}
	};
	return rnaCodon;
}

Codon::~Codon() {

}
