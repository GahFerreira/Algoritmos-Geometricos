/// Explicação sobre a função orientação.

/// Dados 3 pontos ordenados em um plano bidimensional A, B e C, 
/// como descobrir se o ponto C está à esquerda ou direita da reta AB?

/// No papel, traçamos uma reta entre A e B, e então existem três casos:
/// 1. C está à esquerda de AB, ou seja, a reta BC está no sentido antihorário a AB.
/// 2. C está à direita de AB, ou seja, a reta BC está no sentido horário a AB.
/// 3. C está colinear à reta AB.

/// Obs.: A próxima parte fica bem mais intuitiva se você desenhar em algum lugar.
/// Computacionalmente, há dois jeitos de se pensar para chegar em uma resposta equivalente à do papel. Uma é produto vetorial e a outra:
/// A reta AB tem uma inclinação. Ela se dá pela variação no y dividido pela variação no x. Ou seja: (yB - yA) / (xB - xA).
/// A reta BC também tem uma inclinação: (yC - yB) / (xC - xB).
/// Caso a inclinação de AB seja menor que a inclinação de BC, então BC está no sentido antihorário a AB.
/// Caso a inclinação de AB seja maior que a inclinação de BC, então BC está no sentido horário a AB.
/// Caso as inclinações de AB e de BC sejam iguais, então AB e BC são colineares.

/// A comparação entre as fórumlas é: (yB - yA) / (xB - xA) <=> (yC - yB) / (xC - xB) pode ser reformulada assim:
/// (yB - yA) * (xC - xB) <=> (yC - yB) * (xB * xA).
/// Assim, se trocarmos as comparações (<=>) por uma subtração, chegamos a três possíveis respostas:
/// 1. Se for positivo, então AB tem maior inclinação que BC.
/// 2. Se for negativo, então AB tem menor inclinação que BC.
/// 3. Se for 0, então elas tem a mesma inclinação.

/// Dessa forma, podemos traduzir a ideia de orientação pra computação.
/// Disclaimer: por algum motivo, é irrelevante reformular a comparação, mesmo algum dos termos sendo negativo. Deve haver com álgebra.

int orient (Ponto p, Ponto q, Ponto r)
{
    long long int result,
                  p_x = p.get_x(), p_y = p.get_y(),
                  q_x = q.get_x(), q_y = q.get_y(),
                  r_x = r.get_x(), r_y = r.get_y();

    result = ( (q_x - p_x) * (r_y - p_y) - (r_x - p_x) * (q_y - p_y) ); // Determinante (ou produto vetorial bidimensional)

    if (result < 0) return DIR; // -1
    else if (result == 0) return COLINEAR;  // 0
    else return ESQ;    // 1
}