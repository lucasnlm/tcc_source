#ifndef MODBUS_HEADER_HPP_INCLUDED
#define MODBUS_HEADER_HPP_INCLUDED

namespace controller
{
    namespace modbus
    {
        /**
         * Descreve o cabeçalho de uma requisição modbus.
         **/
        class Header
        {
            public:
                /**
                 * Construtor.
                 **/
                Header()
                {}

                /**
                 * @return Retorna o ID da transação.
                 **/
                uint16_t getTransition() const
                {
                    return this->transaction_id.word;
                }

                /**
                 * @return Retorna o ID da unidade.
                 **/
                uint8_t getUnit() const
                {
                    return this->unit;
                }

                /**
                 * @return Retorna o código da Função.
                 **/
                uint8_t getFunctionCode() const
                {
                    return this->function_code;
                }

            protected:
                // Transaction ID. Not important.
                // Usually zero when making a request, the server will copy them faithfully into the response.
                Word transaction_id;

                // Protocol number. Must be zero.
                Word protocol;

                // Equal to the number of bytes which follow
                Word length;

                // Unit number.
                uint8_t unit;

                // Function code.
                uint8_t function_code;
        };
    }
}

#endif
