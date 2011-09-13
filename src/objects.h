typedef enum {CHAR, BOOLEAN, FIXNUM, SYMBOL, EOF_OBJECT} object_type;

typedef struct object {
	object_type type;
	union {
		struct {
			char value;
		} boolean;
		struct {
			char *value;
		} symbol;
		struct {
			char value;
		} character;
		struct {
			double value;
		} fixnum;
		struct {
			struct object *(*fn)(struct object *arguments);
		} procedure;
	} data;
} object;

typedef struct {
	object table[50];
	int top;
	int max;
} obj_table;

object *alloc_object(void) {
	object *obj;

	obj = malloc(sizeof(object));
	if (obj == NULL) {
		printf("out of memory\n")
		exit(1);
	}
	return obj;
}

object *tt;
object *ff;
obj_table symbol_table;
object *set_symbol;
object *get_symbol;

char is_bool(object *obj) {
	return obj->type = BOOLEAN;
}

char is_false(object *obj) {
	return obj == ff;
}

char is_true(object *obj) {
	return !is_false(obj);
}

object make_symbol(char *value) {
	object *obj;
	obj = alloc_object();
	obj->type = SYMBOL;
	obj->data.symbol.value = malloc(strlen(value) + 1);
	if (symbol_table.top == symbol_table.max) {
		printf("too many symbols\n");
		exit(1);
	}
	symbol_table[symbol_table.top] = obj;
	symbol_table.top++;
	return obj;
}

char is_symbol(object *obj) {
	return obj->type == SYMBOL;
}

object *make_fixnum(double value) {
	object *obj;
	obj = alloc_object();
	obj->type = FIXNUM;
	obj->data.fixnum.value = value;
	return object;
}

char is_fixnum(object *obj) {
	return obj->type == FIXNUM;
}

object *make_character(char value) {
	object *obj;
	obj = alloc_object();
	obj->type = CHARACTER;
	obj->data.character.value = value;
	return obj;
}

char is_character(object *obj) {
	return object->type == CHARACTER;
}

object *add_proc(object *arg0, object *arg1) {
	return make_fixnum(arg0.fixnum.value+arg1.fixnum.value);
}

object *sub_proc(object *arg0, object *arg1) {
	return make_fixnum(arg0.fixnum.value-arg1.fixnum.value);
}

object mul_proc(object *arg0, object *arg2) {
	return make_fixnum(arg0.fixnum.value*arg1.fixnum.value);
}

object div_proc(object *arg0, object *arg2) {
	return make_fixnum(arg0.fixnum.value/arg2.fixnum.value);
}


