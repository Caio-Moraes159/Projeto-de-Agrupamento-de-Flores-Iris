<h1>Projeto de Agrupamento de Flores Iris</h1>

<p>Este projeto implementa um algoritmo de clustering em C++ para agrupar flores Iris com base na largura e altura da pétala. O objetivo é organizar as flores em k grupos, onde flores similares são alocadas no mesmo grupo. A espécie da flor não é utilizada na geração dos grupos, servindo apenas para verificar a "qualidade" dos grupos obtidos.</p>

<h2>Estrutura do Arquivo de Dados</h2>

<ul>
    <li><strong>Número de linhas:</strong> 150</li>
    <li><strong>Número de colunas:</strong> 3</li>
    <li>As linhas representam 50 amostras de três espécies de Flores Iris (<em>Iris setosa</em>, <em>Iris virginica</em>, <em>Iris versicolor</em>).</li>
    <li>As colunas representam:
        <ul>
            <li>Largura da pétala</li>
            <li>Altura da pétala</li>
            <li>Espécie da flor</li>
        </ul>
    </li>
</ul>

<h2>Implementação</h2>
<p>O programa lê o arquivo de dados (aquivo CSV que contém no repositório), solicita ao usuário o número de grupos k, e realiza o agrupamento com base nas distâncias euclidianas das flores aos representantes iniciais dos grupos. O representante de cada grupo é atualizado para o ponto médio das flores naquele grupo, repetindo o processo um número definido de vezes.</p>

<h2>Como Compilar e Executar</h2>
<p>Para compilar e executar o programa, siga os passos abaixo:</p>
<ol>
    <li>Abra o terminal ou prompt de comando.</li>
    <li>Navegue até o diretório onde os arquivos <code>Trabalho_final.cpp</code> e <code>iris_petalas.csv</code> estão localizados.</li>
    <li>Compile os arquivos usando o comando:
        <pre>
g++ Trabalho_final.cpp -o flores
        </pre>
    </li>
    <li>Execute o programa com o comando:
        <pre>
./flores
        </pre>
    </li>
</ol>


<h2>Saída</h2>
<p>O programa gera um novo arquivo de dados adicionando uma quarta coluna, que indica o número do grupo ao qual cada flor foi alocada.</p>
<p>Todo esse processo é feito por cálculos que no final do código é criado uma aquivo, que nesse aquivo ele delimita grupos das quais flores pertencem, flores iguais faram parte do mesmo grupos, sendo realizado processo de cálculos com a largura e altura da pétala</p>
<p>Segue abaixo a imagem de saída do prompt:</p>

![image](https://github.com/user-attachments/assets/dcba026d-ab90-4221-97f6-9f89fbdfe66e)

<h2>Licença</h2>
<p>Este projeto é licenciado sob a licença MIT</p>
    
