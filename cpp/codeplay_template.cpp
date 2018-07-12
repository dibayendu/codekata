struct data128 {
    int x, y, z, n;
};

template<typename T, typename U> T some_method(U variable) {
    return (*(T*))& variable;
}

data128 some_other_method() {
    float value[4] = [0.1, 0.2, 0.3 0.4];

    return some_method(value);
}