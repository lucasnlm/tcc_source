#include "write_register.hpp"

namespace controller
{
    namespace modbus
    {
        WriteRegister::WriteRegister(const uint8_t* buffer)
        {
            // ID da Transação
            transaction_id.high = buffer[0];
            transaction_id.low = buffer[1];

            // Protocolo, sempre zero
            // Consome buffer[2] e buffer[3]
            
            // Comprimento da Mensagem
            length.high = buffer[4];
            length.low = buffer[5];
            
            // ID da unidade.
            unit = buffer[6];
            
            // Código da Função
            function_code = buffer[7];
            
            // Número de Referência
            output_address.high = buffer[8];
            output_address.low = buffer[9];
            
            // Quantidade de bits que deve ser retornados
            output_value.high = buffer[10];
            output_value.low = buffer[11];
        }
    }
}
