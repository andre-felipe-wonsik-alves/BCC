let counter = localStorage.getItem("studentCount") || 0;
counter++;
localStorage.setItem("studentCount", counter);

document.getElementById(
  "studentCountDisplay"
).innerText = `Quantidade de alunos corrigidos: ${counter}`;

document
  .getElementById("formComp")
  .addEventListener("submit", function (event) {
    event.preventDefault();

    const name = document.getElementById("name").value;
    if (!name) {
      return alert("Por favor, preencha o nome do aluno.");
    }
    const comp1 = document.querySelector('input[name="comp1"]:checked').value;
    const comp2 = document.querySelector('input[name="comp2"]:checked').value;
    const comp3 = document.querySelector('input[name="comp3"]:checked').value;
    const comp4 = document.querySelector('input[name="comp4"]:checked').value;
    const comp5 = document.querySelector('input[name="comp5"]:checked').value;

    let csvContent = localStorage.getItem("formData") || "Nome,Competência 1\n";

    csvContent += `${name},${comp1},${comp2},${comp3},${comp4},${comp5}\n`;

    localStorage.setItem("formData", csvContent);

    const blob = new Blob([csvContent], { type: "text/csv;charset=utf-8;" });
    const link = document.createElement("a");
    const url = URL.createObjectURL(blob);

    link.setAttribute("href", url);
    link.setAttribute("download", "form_data.csv");
    link.style.visibility = "hidden";
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
  });

document.getElementById("formComp").reset();
