# Projeto STM32F103C8T6 com Bluetooth modelo HC-05

Este projeto é desenvolvido para o microcontrolador STM32F103C8T6 com a utilização do FreeRTOS para o gerenciamento de tarefas. O objetivo é integrar o módulo Bluetooth HC-05 para comunicação sem fio, permitindo que o STM32 se conecte a dispositivos Bluetooth e receba ou envie dados.

A primeira etapa do projeto envolve a comunicação com o módulo HC-05, utilizando comandos AT para configurar o módulo e realizar a comunicação. As funções dos comandos AT serão implementadas em tarefas do FreeRTOS, proporcionando um controle eficiente e em tempo real das operações de envio e recepção de dados via Bluetooth. As tarefas irão gerenciar a comunicação, configurando o módulo Bluetooth, realizando a conexão e permitindo a troca de informações entre o STM32 e dispositivos Bluetooth.

No momento, as funções relacionadas aos comandos AT ainda serão implementadas, com o intuito de configurar o HC-05 para diferentes modos de operação, como o modo de paring, verificação de status e envio de dados.
