# Catarata
# Cataract---Image-Processing-in-C

Projeto de Processamento de Imagens em C: Identificação de Catarata
Autores: Emanuel Costa Betcel e Max William Souto Filgueira

Funcionalidades do programa: O programa recebe como entrada uma imagem .ppm e sua saída é esta imagem com a pupila segmentada e o diagnóstico de catarata, junto com a porcentagem aproximada do comprometimento da pupila.

Funcionamento: O código é executando recebendo como argumento a imagem a ser analisada e o nome do arquivo que será criado, faz a leitura da imagem e os pixels são convertidos para apresentarem tons de cinza. Este processo permite a aplicação dos filtros que serão usados para permitir a identificação dos círculos. Após isso, a imagem é submetida ao filtro de Gauss, cujo objetivo é eliminar ruídos e borrar a imagem, preparando-a para o filtro de Sobel. A matriz do Sobel identifica arestas e as realça. Depois o filtro de Gauss é executado mais uma vez para melhor acabamento.
Implementamos o método de Otsu para detectar o thresholding a ser utilizado na binarização. A transformada de Hough foi a técnica computacional utilizada para a detecção dos círculos.
A pupila é detectada, e é feita a contagem da quantidade de pixels de catarata presentes, apresentando o diagnóstico e a porcentagem de comprometimento. O flash não é levado em consideração no programa e é considerado como uma certa margem de erro.

Compilando e executando: O programa não necessita de nenhuma biblioteca além das padrões do C, sendo necessário apenas compilar com make main. O formato para execução é ./proj Nomedoarquivo.ppm Nomedoarquivoasercriado.ppm.

Contribuição de cada participante: 
Emanuel Costa Betcel: Implementação dos filtros, recorte da pupila e diagnóstico, documentação do projeto.
Max William Souto Filgueira: Leitura da imagem e conversão para tons de cinza, implementação da método de Otsu e Transformada de Hough.
