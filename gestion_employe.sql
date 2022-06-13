-- phpMyAdmin SQL Dump
-- version 4.9.5deb2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mer. 08 juin 2022 à 12:06
-- Version du serveur :  8.0.29-0ubuntu0.20.04.3
-- Version de PHP : 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `gestion_employe`
--

-- --------------------------------------------------------

--
-- Structure de la table `adresse`
--

CREATE TABLE `adresse` (
  `id` int NOT NULL,
  `ligne` varchar(100) CHARACTER SET utf8mb3 COLLATE utf8_general_ci NOT NULL,
  `departement` varchar(15) NOT NULL,
  `commune` varchar(45) NOT NULL,
  `telephone` varchar(45) CHARACTER SET utf8mb3 COLLATE utf8_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Déchargement des données de la table `adresse`
--

INSERT INTO `adresse` (`id`, `ligne`, `departement`, `commune`, `telephone`) VALUES
(1, '13, Rue Louis Juste', 'Ouest', 'Delmas', '44356783'),
(2, '45, Rue Laplante', 'Ouest', 'Carrefour', '45632456'),
(4, '43, Rue Lubin', 'Ouest', 'Petit-Goave', '54678909'),
(5, '76, ru quatre', 'Ouest', 'Petite Riviere', '44108127'),
(6, '845, Mariani 10', 'Ouest', 'Gressier', '4565758'),
(7, '234, rue blanc', 'Ouest', 'Port-de-Paix', '78965678'),
(8, '758, Rue Lacroix', 'Ouest', 'Delmas', '83790765'),
(10, ' bnhgh', 'Nord', 'jdjttr', '78769');

-- --------------------------------------------------------

--
-- Structure de la table `affectation`
--

CREATE TABLE `affectation` (
  `id_employe` int NOT NULL,
  `id_projet` int NOT NULL,
  `date_affectation` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Déchargement des données de la table `affectation`
--

INSERT INTO `affectation` (`id_employe`, `id_projet`, `date_affectation`) VALUES
(3, 1, '2022-06-08 14:35:09'),
(3, 2, '2022-06-08 14:35:26');

-- --------------------------------------------------------

--
-- Structure de la table `employe`
--

CREATE TABLE `employe` (
  `id` int NOT NULL,
  `id_fonction` int NOT NULL,
  `id_service` int NOT NULL,
  `nom` varchar(45) DEFAULT NULL,
  `prenom` varchar(45) DEFAULT NULL,
  `mail` varchar(60) CHARACTER SET utf8mb3 COLLATE utf8_general_ci NOT NULL,
  `telephone` varchar(45) DEFAULT NULL,
  `salaire` double DEFAULT NULL,
  `date_creation` timestamp NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Déchargement des données de la table `employe`
--

INSERT INTO `employe` (`id`, `id_fonction`, `id_service`, `nom`, `prenom`, `mail`, `telephone`, `salaire`, `date_creation`) VALUES
(3, 1, 3, 'Lajeanty', 'Louis Midosn', 'mail@mail.com', '45654566', 100000, '2022-06-08 12:45:15');

-- --------------------------------------------------------

--
-- Structure de la table `fonction`
--

CREATE TABLE `fonction` (
  `id` int NOT NULL,
  `libelle` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Déchargement des données de la table `fonction`
--

INSERT INTO `fonction` (`id`, `libelle`) VALUES
(1, 'Directeur'),
(2, 'Assistant Directeur'),
(3, 'Scrum Master');

-- --------------------------------------------------------

--
-- Structure de la table `projet`
--

CREATE TABLE `projet` (
  `id` int NOT NULL,
  `nom` varchar(45) NOT NULL,
  `duree` int DEFAULT NULL,
  `cout_estime` double DEFAULT NULL,
  `etat_actuel` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Déchargement des données de la table `projet`
--

INSERT INTO `projet` (`id`, `nom`, `duree`, `cout_estime`, `etat_actuel`) VALUES
(1, 'Revelation', 234, 1000000, 'Creer'),
(2, 'Psycopg2', 24, 20889, 'Demarrer');

-- --------------------------------------------------------

--
-- Structure de la table `service`
--

CREATE TABLE `service` (
  `id` int NOT NULL,
  `id_adresse` int NOT NULL,
  `libelle` varchar(45) NOT NULL,
  `etat` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Déchargement des données de la table `service`
--

INSERT INTO `service` (`id`, `id_adresse`, `libelle`, `etat`) VALUES
(1, 1, 'Comptabilite', 'Actif'),
(2, 5, 'Administration', 'Inactif'),
(3, 6, 'Direction', 'Actif'),
(4, 5, 'Gestion', 'Actif'),
(5, 5, 'Petit Personel', 'Actif');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `adresse`
--
ALTER TABLE `adresse`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `affectation`
--
ALTER TABLE `affectation`
  ADD PRIMARY KEY (`id_employe`,`id_projet`),
  ADD KEY `id_projet` (`id_projet`);

--
-- Index pour la table `employe`
--
ALTER TABLE `employe`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `mail_UNIQUE` (`mail`),
  ADD KEY `id_fonction` (`id_fonction`),
  ADD KEY `id_service` (`id_service`);

--
-- Index pour la table `fonction`
--
ALTER TABLE `fonction`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `projet`
--
ALTER TABLE `projet`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `service`
--
ALTER TABLE `service`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_adresse` (`id_adresse`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `adresse`
--
ALTER TABLE `adresse`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT pour la table `employe`
--
ALTER TABLE `employe`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `fonction`
--
ALTER TABLE `fonction`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `projet`
--
ALTER TABLE `projet`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `service`
--
ALTER TABLE `service`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `affectation`
--
ALTER TABLE `affectation`
  ADD CONSTRAINT `affectation_ibfk_1` FOREIGN KEY (`id_employe`) REFERENCES `employe` (`id`),
  ADD CONSTRAINT `affectation_ibfk_2` FOREIGN KEY (`id_projet`) REFERENCES `projet` (`id`);

--
-- Contraintes pour la table `employe`
--
ALTER TABLE `employe`
  ADD CONSTRAINT `employe_ibfk_1` FOREIGN KEY (`id_fonction`) REFERENCES `fonction` (`id`),
  ADD CONSTRAINT `employe_ibfk_2` FOREIGN KEY (`id_service`) REFERENCES `service` (`id`);

--
-- Contraintes pour la table `service`
--
ALTER TABLE `service`
  ADD CONSTRAINT `service_ibfk_1` FOREIGN KEY (`id_adresse`) REFERENCES `adresse` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
