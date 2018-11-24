-- MySQL dump 10.13  Distrib 8.0.13, for Win64 (x86_64)
--
-- Host: localhost    Database: trabalho_ps2
-- ------------------------------------------------------
-- Server version	8.0.13

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `doacao`
--

DROP TABLE IF EXISTS `doacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `doacao` (
  `id_doacao` int(11) NOT NULL AUTO_INCREMENT,
  `id_residuo` int(11) NOT NULL,
  `id_usuario` int(11) NOT NULL,
  `quantidade` int(11) NOT NULL,
  `disponibilidade` int(11) NOT NULL,
  PRIMARY KEY (`id_doacao`),
  KEY `residuo_doacao_idx` (`id_residuo`),
  KEY `doacao_usuario_idx` (`id_usuario`),
  CONSTRAINT `doacao_residuo` FOREIGN KEY (`id_residuo`) REFERENCES `residuo` (`id_residuo`),
  CONSTRAINT `doacao_usuario` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doacao`
--

LOCK TABLES `doacao` WRITE;
/*!40000 ALTER TABLE `doacao` DISABLE KEYS */;
/*!40000 ALTER TABLE `doacao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `residuo`
--

DROP TABLE IF EXISTS `residuo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `residuo` (
  `id_residuo` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(45) NOT NULL,
  `tipo` int(11) NOT NULL,
  `armazenamento` varchar(100) NOT NULL,
  PRIMARY KEY (`id_residuo`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `residuo`
--

LOCK TABLES `residuo` WRITE;
/*!40000 ALTER TABLE `residuo` DISABLE KEYS */;
INSERT INTO `residuo` VALUES (1,'Pilha',1,'Local seco, com temperatura amena e devidamente protegido.');
/*!40000 ALTER TABLE `residuo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `residuo_interesse`
--

DROP TABLE IF EXISTS `residuo_interesse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `residuo_interesse` (
  `id_residuo_interesse` int(11) NOT NULL AUTO_INCREMENT,
  `id_residuo` int(11) DEFAULT NULL,
  `id_receptor` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_residuo_interesse`),
  KEY `residuo_interesse_residuo_idx` (`id_residuo`),
  KEY `residuo_interesse_receptor_idx` (`id_receptor`),
  CONSTRAINT `residuo_interesse_receptor` FOREIGN KEY (`id_receptor`) REFERENCES `usuario` (`id_usuario`),
  CONSTRAINT `residuo_interesse_residuo` FOREIGN KEY (`id_residuo`) REFERENCES `residuo` (`id_residuo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `residuo_interesse`
--

LOCK TABLES `residuo_interesse` WRITE;
/*!40000 ALTER TABLE `residuo_interesse` DISABLE KEYS */;
/*!40000 ALTER TABLE `residuo_interesse` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `solicitacao`
--

DROP TABLE IF EXISTS `solicitacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `solicitacao` (
  `id_solicitacao` int(11) NOT NULL AUTO_INCREMENT,
  `id_doador` int(11) NOT NULL,
  `id_receptor` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  `proposta` varchar(200) DEFAULT NULL,
  `resposta` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`id_solicitacao`),
  KEY `solicitacao_doador_idx` (`id_doador`),
  KEY `solicitacao_receptor_idx` (`id_receptor`),
  CONSTRAINT `solicitacao_doador` FOREIGN KEY (`id_doador`) REFERENCES `usuario` (`id_usuario`),
  CONSTRAINT `solicitacao_receptor` FOREIGN KEY (`id_receptor`) REFERENCES `usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `solicitacao`
--

LOCK TABLES `solicitacao` WRITE;
/*!40000 ALTER TABLE `solicitacao` DISABLE KEYS */;
/*!40000 ALTER TABLE `solicitacao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `usuario`
--

DROP TABLE IF EXISTS `usuario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `usuario` (
  `id_usuario` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(45) NOT NULL,
  `documento` varchar(20) NOT NULL,
  `telefone` varchar(20) NOT NULL,
  `endereco` varchar(100) NOT NULL,
  `senha` varchar(45) NOT NULL,
  PRIMARY KEY (`id_usuario`),
  UNIQUE KEY `documento_UNIQUE` (`documento`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `usuario`
--

LOCK TABLES `usuario` WRITE;
/*!40000 ALTER TABLE `usuario` DISABLE KEYS */;
/*!40000 ALTER TABLE `usuario` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-11-24 18:34:36
