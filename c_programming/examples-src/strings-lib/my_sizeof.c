
void *my_sizeof(void *data) {
	return (void *)((data+1) - (data));
}
