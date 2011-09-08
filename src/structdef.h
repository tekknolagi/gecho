#ifndef STRUCTDEF_H_
#define STRUCTDEF_H_
mode list[] = {
	{"@default", true},
	{"@transparent", false},
	{"@tracker", false},
};

const_list cons[] = {
	{"#t", 1},
	{"#true", 1},
	{"#f", 0},
	{"#false", 0},
	{"#pi", M_PI},
	{"#e", M_E},
	{"#phi", M_PHI},
};

#endif
