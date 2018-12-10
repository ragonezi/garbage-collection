#include "../includes/gerenciamento.h"

Gerenciamento::Gerenciamento() : Conexao::Conexao()
{
}

bool Gerenciamento::login(Usuario &usuario, std::string senha)
{
    std::string consulta = "SELECT * FROM usuario WHERE documento = '" + usuario.getDocumento() + "' AND senha = '" + senha + "'";

    if (this->selecionar(consulta))
    {
        while ((linhas = mysql_fetch_row(this->resp)) != NULL)
        {
            usuario.setIdPessoa(linhas[0]);
            usuario.setNome(linhas[1]);
            usuario.setTelefone(linhas[3]);
            usuario.setEndereco(linhas[4]);
        }
        // Gerenciamento::limparResultado();
        std::vector<Doacao> doacoes = this->getDoacoes(usuario.getIdPessoa(), 0, true);
        for (std::vector<Doacao>::iterator it = doacoes.begin(); it != doacoes.end(); ++it)
        {
            usuario.addDoacao(*it);
        }
        std::vector<Solicitacao> solicitacoes = this->getSolicitacoes(usuario.getIdPessoa(), true);
        for (std::vector<Solicitacao>::iterator it = solicitacoes.begin(); it != solicitacoes.end(); ++it)
        {
            usuario.addSolicitacao(*it);
        }
        return true;
    }
    Gerenciamento::limparResultado();
    return false;
}

bool Gerenciamento::disponibilidadeDocumento(std::string documento)
{
    std::string consulta = "SELECT * FROM usuario WHERE documento = '" + documento + "'";
    bool disponivel = !this->selecionar(consulta);
    Gerenciamento::limparResultado();
    return disponivel;
}

bool Gerenciamento::cadastro(Usuario &usuario, std::string senha)
{
    std::string comando = "INSERT INTO usuario (nome, documento, telefone, endereco, senha) VALUES ('" + usuario.getNome() + "', '" + usuario.getDocumento() + "', '" + usuario.getTelefone() + "', '" + usuario.getEndereco() + "', '" + senha + "')";

    int resultado = this->inserir(comando);
    if (resultado > 0)
    {
        usuario.setIdPessoa(std::to_string(resultado));
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<Residuo> Gerenciamento::getResiduos(int tipoResiduo)
{
    std::string consulta = "SELECT * FROM residuo WHERE tipo = " + std::to_string(tipoResiduo);

    std::vector<Residuo> residuos;

    if (this->selecionar(consulta))
    {
        while ((linhas = mysql_fetch_row(this->resp)) != NULL)
        {
            Residuo residuo = Residuo(linhas[1], linhas[3], (int)linhas[2]);
            residuo.setIdResiduo(linhas[0]);
            residuos.push_back(residuo);
        }
    }
    Gerenciamento::limparResultado();
    return residuos;
}

bool Gerenciamento::cadastrarDoacao(Doacao &doacao)
{
    std::string idResiduo = doacao.getResiduo().getIdResiduo();
    std::string idDoador = doacao.getDoador().getIdPessoa();
    std::string comando = "INSERT INTO doacao (id_residuo, id_usuario, quantidade, disponibilidade) VALUES (" + idResiduo + ", " + idDoador + ", '" + doacao.getQuantidade() + "', " + std::to_string(doacao.getDisponibilidade()) + ")";

    int resultado = this->inserir(comando);
    if (resultado > 0)
    {
        doacao.setIdDoacao(std::to_string(resultado));
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<Doacao> Gerenciamento::getDoacoes(std::string idUsuario, int tipoResiduo, bool minhasDoacoes)
{
    std::string campos = "doacao.id_doacao, quantidade, residuo.id_residuo, residuo.nome, residuo.armazenamento, usuario.id_usuario, usuario.nome, usuario.documento, usuario.telefone, usuario.endereco";
    std::string condicaoIdUsuario = minhasDoacoes ? " = " : " != ";
    std::string condicaoUsuario = "usuario.id_usuario = doacao.id_usuario AND usuario.id_usuario " + condicaoIdUsuario + idUsuario + " AND disponibilidade = 1";
    std::string condicaoTipoResiduo = tipoResiduo != 0 ? " AND tipo = " + std::to_string(tipoResiduo) : "";
    std::string condicaoResiduo = "residuo.id_residuo = doacao.id_residuo" + condicaoTipoResiduo;
    std::string consulta = "SELECT " + campos + " FROM doacao INNER JOIN residuo ON " + condicaoResiduo + " INNER JOIN usuario ON " + condicaoUsuario;

    std::vector<Doacao> doacoes;

    if (this->selecionar(consulta))
    {
        while ((linhas = mysql_fetch_row(this->resp)) != NULL)
        {

            std::vector<std::string> camposDoacao = {linhas[0], linhas[1], linhas[2], linhas[3], linhas[4], linhas[5], linhas[6], linhas[7], linhas[8], linhas[9]};

            Doacao doacao = Gerenciamento::configurarDoacao(camposDoacao, tipoResiduo);

            doacoes.push_back(doacao);
        }
    }
    // Gerenciamento::limparResultado();
    return doacoes;
}

Doacao Gerenciamento::configurarDoacao(std::vector<std::string> campos, int tipoResiduo)
{
    Residuo residuo = Residuo(campos[3], campos[4], tipoResiduo);
    residuo.setIdResiduo(campos[3]);

    Doador doador = Doador(campos[6], campos[7], campos[8], campos[9]);
    doador.setIdPessoa(campos[5]);

    Doacao doacao = Doacao(residuo, doador, campos[1], 1);
    doacao.setIdDoacao(campos[0]);

    return doacao;
}

bool Gerenciamento::cadastrarSolicitacao(Solicitacao &solicitacao)
{
    std::string idDoacao = solicitacao.getDoacao().getIdDoacao();
    std::string idReceptor = solicitacao.getReceptor().getIdPessoa();
    std::string tipoEntrega = std::to_string(solicitacao.getTipoEntrega());
    std::string campos = "id_doacao, id_receptor, status, proposta, resposta, tipo_entrega, data_entrega";
    std::string valores = idDoacao + ", " + idReceptor + ", 1, '" + solicitacao.getProposta() + "', '', " + tipoEntrega + ", '" + solicitacao.getDataEntrega() + "'";
    std::string comando = "INSERT INTO solicitacao (" + campos + ") VALUES (" + valores + ")";

    int resultado = this->inserir(comando);
    if (resultado > 0)
    {
        solicitacao.setIdSolicitacao(std::to_string(resultado));
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<Solicitacao> Gerenciamento::getSolicitacoes(std::string id, bool minhasSolicitacoes)
{
    std::vector<Solicitacao> solicitacoes;

    std::string campos = "d.id_doacao, d.quantidade, re.id_residuo, re.nome, re.armazenamento, dr.id_usuario, dr.nome, dr.documento, dr.telefone, dr.endereco, r.id_usuario, r.nome, r.documento, r.telefone, r.endereco, sl.id_solicitacao, proposta, resposta, tipo_entrega, data_entrega, re.tipo";

    std::string condicaoDoacao = "d.id_doacao = sl.id_doacao AND d.disponibilidade = 1 AND sl.status = 1";

    std::string condicaoReceptor = "r.id_usuario = sl.id_receptor";

    std::string condicaoDoador = "dr.id_usuario = d.id_usuario";

    std::string condicaoResiduo = "re.id_residuo = d.id_residuo";

    condicaoReceptor += minhasSolicitacoes ? (" AND r.id_usuario = " + id) : "";

    condicaoDoacao += !minhasSolicitacoes ? (" AND d.id_doacao = " + id) : "";

    std::string consulta = "SELECT " + campos + " FROM solicitacao as sl INNER JOIN doacao as d ON " + condicaoDoacao + " INNER JOIN usuario as r ON " + condicaoReceptor + " INNER JOIN residuo as re ON " + condicaoResiduo + " INNER JOIN usuario as dr ON " + condicaoDoador;

    if (this->selecionar(consulta))
    {
        while ((linhas = mysql_fetch_row(this->resp)) != NULL)
        {
            std::string proposta = linhas[16] ? linhas[16] : "";
            std::vector<std::string> camposSolicitacao = {
                linhas[0],
                linhas[1],
                linhas[2],
                linhas[3],
                linhas[4],
                linhas[5],
                linhas[6],
                linhas[7],
                linhas[8],
                linhas[9],
                linhas[10],
                linhas[11],
                linhas[12],
                linhas[13],
                linhas[14],
                linhas[15],
                proposta,
                "",
                linhas[18],
                linhas[19]};

            Solicitacao solicitacao = this->configurarSolicitacao(camposSolicitacao);
            solicitacoes.push_back(solicitacao);
        }
    }
    return solicitacoes;
}

Solicitacao Gerenciamento::configurarSolicitacao(std::vector<std::string> camposSolicitacao)
{

    Receptor receptor = Receptor(camposSolicitacao[11], camposSolicitacao[12], camposSolicitacao[13], camposSolicitacao[14]);
    receptor.setIdPessoa(camposSolicitacao[10]);

    std::vector<std::string> camposDoacao = {
        camposSolicitacao[0],
        camposSolicitacao[1],
        camposSolicitacao[2],
        camposSolicitacao[3],
        camposSolicitacao[4],
        camposSolicitacao[5],
        camposSolicitacao[6],
        camposSolicitacao[7],
        camposSolicitacao[8],
        camposSolicitacao[9]};
    Doacao doacao = this->configurarDoacao(camposDoacao, 1);

    Solicitacao solicitacao = Solicitacao(doacao, receptor, 1);
    solicitacao.setProposta(camposSolicitacao[16]);
    solicitacao.setResposta(camposSolicitacao[17]);
    // int tipoEntrega = (int)camposSolicitacao[18];
    solicitacao.setTipoEntrega(1);
    solicitacao.setDataEntrega(camposSolicitacao[19]);
    solicitacao.setIdSolicitacao(camposSolicitacao[15]);

    return solicitacao;
}

bool Gerenciamento::alterarStatusSolicitacao(std::string idSolicitacao, std::string idDoacao, int status)
{
    std::string comando = "UPDATE solicitacao SET status = " + std::to_string(status) + " WHERE id_solicitacao = " + idSolicitacao;

    int resultado = this->alterar(comando);
    if (resultado > 0)
    {
        if (status == 3)
        {
            this->alterarStatusDoacao(idDoacao, 2);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Gerenciamento::alterarStatusDoacao(std::string idDoacao, int status)
{
    std::string comando = "UPDATE doacao SET disponibilidade = " + std::to_string(status) + " WHERE id_doacao = " + idDoacao;

    int resultado = this->alterar(comando);
    if (resultado > 0)
    {
        if (status == 2)
        {
            std::string comandoSolicitacoes = "UPDATE solicitacao SET status = 2 WHERE status != 3 AND id_doacao = " + idDoacao;
            this->alterar(comandoSolicitacoes);
        }
        return true;
    }
    else
    {
        return false;
    }
}

std::map<int, Usuario> Gerenciamento::rankingDoadores()
{
    std::map<int, Usuario> ranking;

    std::string consulta = "SELECT  DISTINCT dr.id_usuario, dr.nome, dr.telefone, COUNT(dr.id_usuario) as numero FROM solicitacao AS s INNER JOIN doacao AS d ON d.id_doacao = s.id_doacao INNER JOIN usuario AS dr ON dr.id_usuario = d.id_usuario AND s.status = 3  GROUP BY dr.id_usuario ORDER BY numero DESC";

    if (this->selecionar(consulta))
    {
        int i = 1;
        while ((linhas = mysql_fetch_row(this->resp)) != NULL)
        {
            Usuario usuario = Usuario(linhas[1], "", linhas[2], linhas[3]);
            ranking[i] = usuario;
            i++;
        }
    }
    return ranking;
}

int Gerenciamento::alterar(std::string comando)
{
    const char *query = comando.c_str();
    int res = mysql_query(&this->getConexao(), query);

    if (!res)
        return 1;
    else
    {
        printf("Erro na inserção %d : %s\n", mysql_errno(&this->getConexao()), mysql_error(&this->getConexao()));
        return 0;
    }
}

int Gerenciamento::inserir(std::string comando)
{
    const char *query = comando.c_str();
    int res = mysql_query(&this->getConexao(), query);

    if (!res)
        return mysql_insert_id(&this->getConexao());
    else
    {
        printf("Erro na inserção %d : %s\n", mysql_errno(&this->getConexao()), mysql_error(&this->getConexao()));
        return 0;
    }
}

bool Gerenciamento::selecionar(std::string consulta)
{
    const char *query = consulta.c_str();
    int conta;
    if (mysql_query(&this->getConexao(), query))
        printf("Erro: %s\n", mysql_error(&this->getConexao()));
    else
    {
        this->resp = mysql_store_result(&this->getConexao()); //recebe a consulta

        if (this->resp)
        {
            return mysql_num_rows(this->resp) > 0;
        }
    }
    return false;
}

void Gerenciamento::limparResultado()
{
    mysql_free_result(this->resp);
}