function somarMatrizes(A, B) {
  const resultado = [];
  for (let i = 0; i < 4; i++) {
    resultado[i] = [];
    for (let j = 0; j < 4; j++) {
      resultado[i][j] = A[i][j] + B[i][j];
    }
  }
  return resultado;
}

function multiplicarPorEscalar(matriz, escalar) {
  const resultado = [];
  for (let i = 0; i < 4; i++) {
    resultado[i] = [];
    for (let j = 0; j < 4; j++) {
      resultado[i][j] = matriz[i][j] * escalar;
    }
  }
  return resultado;
}

function multiplicarMatrizes(A, B) {
  const resultado = [];
  for (let i = 0; i < 4; i++) {
    resultado[i] = [];
    for (let j = 0; j < 4; j++) {
      let soma = 0;
      for (let k = 0; k < 4; k++) {
        soma += A[i][k] * B[k][j];
      }
      resultado[i][j] = soma;
    }
  }
  return resultado;
}

function mostrarMatriz(matriz, nome) {
  console.log(`\nMatriz ${nome}:`);
  for (const linha of matriz) {
    console.log(linha.join("\t"));
  }
}

const A = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 0, 1, 2],
  [3, 4, 5, 6],
];

const B = [
  [6, 5, 4, 3],
  [2, 1, 0, -1],
  [-2, -3, -4, -5],
  [-6, -7, -8, -9],
];

const soma = somarMatrizes(A, B);
const escalar = multiplicarPorEscalar(A, 1 / 10);
const produto = multiplicarMatrizes(A, B);
mostrarMatriz(soma, "A + B");
mostrarMatriz(escalar, "1/10 A");
mostrarMatriz(produto, "A * B");
