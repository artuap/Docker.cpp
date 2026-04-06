# Usamos la imagen oficial de Espressif
FROM espressif/idf:release-v5.1

# Establecer el directorio de trabajo dentro del contenedor
WORKDIR /app

# Instalar dependencias adicionales si las necesitas (ej. herramientas de limpieza)
RUN apt-get update && apt-get install -y \
    ccache \
    && rm -rf /var/lib/apt/lists/*

# Configurar el entrypoint para que los comandos de idf.py estén listos
ENTRYPOINT [ "/opt/esp/entrypoint.sh" ]

# Por defecto, abrir una terminal
CMD [ "/bin/bash" ]
