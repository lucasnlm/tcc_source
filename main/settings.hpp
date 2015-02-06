#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include <string>

namespace controller
{
    enum OperationMode
    {
        REMOTE_TERMINAL = 2,
        CONTROLLER = 4
    };

    class Settings
    {
        public:
            /**
             * Carrega as configurações pré-estabelecidas ou carrega do
             * arquivo "settings.json", se válido.
             **/
            Settings();
            
            /**
             * Carrega as configurações de um arquivo.
             * @param file_name O nome do arquivo.
             **/
            void loadFromFile(const std::string& file_name);
            
            /**
             * @return Retorna a porta HTTP utilizada.
             **/
            int getHttpPort() const
            {
                return http_port;
            }
            
            /**
             * @return Retorna a porta Modbus utilizada.
             **/
            int getModbusPort() const
            {
                return modbus_port;
            }
            
            /**
             * @return Retorna true o Watch Dog deve ser ativado.
             **/
            bool getWatchDog() const
            {
                return watch_dog != 0;
            }
            
            /**
             * @return Retorna o tempo de scan do sistema.
             **/
            int getScanTime() const 
            {
                return scan_time;
            }
            
            /**
             * Modifica o tempo de scan.
             * @param scan O novo tempo de scan.
             **/
            void setScanTime(int scan)
            {
                if(scan >= 20)
                {
                    this->scan_time = scan;
                }
            }
            
            /**
             * Salva as configurações atuais.
             **/
            void save(const char* path);
            
            /**
             * Carrega as configurações.
             **/
            static void load();

        private:
            /**
             * Carrega as configurações default.
             **/
            void loadDefault();
            
            /**
             * Carrega as informações de uma string Json.
             * @param json A string contendo as configurações em Json.
             **/
            bool loadJson(const std::string& json);

        private:
            // A porta HTTP, geralmente 80 ou 8080.
            int http_port = 80;
            
            // A porta MODBUS, geralmente 502 ou 1502.
            int modbus_port = 502;
            
            // Verificador do Watch Dog (ativado != 0).
            int watch_dog = 1;
            
            // O tempo de scan.
            int scan_time = 100;
    };
    
    /**
     * @return Retorna as configurações utilizadas pelo sistema.
     **/
    Settings& getSettings();
}


#endif // SETTINGS_HPP_INCLUDED
