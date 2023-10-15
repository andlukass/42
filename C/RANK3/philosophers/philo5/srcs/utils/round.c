int	round2(int value) {
    int centena = (value / 100) * 100; // Obtém o múltiplo de 100 mais próximo
    int resto = value % 100; // Obtém o value do resto

    // Arredonda para cima ou para baixo com base no value do resto
    if (resto < 50) {
        return centena;
    } else {
        return centena + 100;
    }
}